/**
 * Renders a sprite sheet inside raycaster-386, headless, from the 8 directions.
 *
 * Usage: node snapshot.mjs <name> [animation]
 *   reads  ../output/<name>.png and ../output/<name>.json
 *   writes ../output/<name>.engine.png: one view per direction, labelled with
 *          the direction the engine picked. The character must look towards
 *          the light strip on the floor in every view.
 */
import { Canvas, Image, ImageData, createCanvas, loadImage } from '@napi-rs/canvas';
import { readFileSync, writeFileSync } from 'node:fs';
import { dirname, join } from 'node:path';
import { fileURLToPath } from 'node:url';

// Just enough DOM for the engine, as in raycaster-386's tests/harness/dom.ts.
globalThis.HTMLCanvasElement = Canvas;
globalThis.HTMLImageElement = Image;
globalThis.Image = Image;
globalThis.ImageData = ImageData;
globalThis.CanvasGradient ??= class CanvasGradient {};
globalThis.document = {
	createElement(tag) {
		if (tag !== 'canvas') {
			throw new Error(`dom shim: only <canvas> is supported, got <${tag}>`);
		}
		return createCanvas(1, 1);
	},
};

const { createScene, orbitForDirection } = await import('./scene.mjs');

const here = dirname(fileURLToPath(import.meta.url));
const output = join(here, '..', 'output');
const [name, animation] = process.argv.slice(2);
if (!name) {
	console.error('usage: node snapshot.mjs <name> [animation]');
	process.exit(1);
}

async function canvasFrom(path) {
	const image = await loadImage(readFileSync(path));
	const c = createCanvas(image.width, image.height);
	c.getContext('2d').drawImage(image, 0, 0);
	return c;
}

const W = 240;
const H = 160;
const scene = createScene({
	walls: await canvasFrom(join(here, 'assets', 'walls.png')),
	flats: await canvasFrom(join(here, 'assets', 'flats.png')),
	sheet: await canvasFrom(join(output, `${name}.png`)),
	tileset: JSON.parse(readFileSync(join(output, `${name}.json`), 'utf8')),
	width: W,
	height: H,
});
if (animation) {
	scene.setAnimation(animation);
}

const COLS = 4;
const sheet = createCanvas(W * COLS, H * 2);
const ctx = sheet.getContext('2d');
ctx.font = '12px sans-serif';
for (let d = 0; d < 8; ++d) {
	const picked = scene.render(orbitForDirection(d), 2.2);
	const x = (d % COLS) * W;
	const y = Math.floor(d / COLS) * H;
	ctx.drawImage(scene.renderer.renderCanvas, x, y);
	ctx.fillStyle = picked === d ? '#ffff00' : '#ff0000';
	ctx.fillText(`direction ${picked}`, x + 6, y + 14);
	ctx.strokeStyle = '#000000';
	ctx.strokeRect(x + 0.5, y + 0.5, W - 1, H - 1);
}
const out = join(output, `${name}.engine.png`);
writeFileSync(out, sheet.toBuffer('image/png'));
console.log(out);
