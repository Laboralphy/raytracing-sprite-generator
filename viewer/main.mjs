import { Canvas } from '@laboralphy/raycaster386';
import { createScene } from './scene.mjs';

const screen = document.getElementById('screen');
const sheetInput = document.getElementById('sheet');
const animSelect = document.getElementById('anim');
const spin = document.getElementById('spin');
const readout = document.getElementById('readout');
const target = screen.getContext('2d');
target.imageSmoothingEnabled = false;

const params = new URLSearchParams(location.search);
sheetInput.value = params.get('sheet') ?? sheetInput.value;

const [walls, flats] = await Canvas.loadCanvases(['assets/walls.png', 'assets/flats.png']);
let scene = null;
let orbit = 0;
let distance = 2.2;
const keys = new Set();

async function load(name) {
	// output/ is served as the public directory (see vite.config.js).
	const [sheet] = await Canvas.loadCanvases([`/${name}.png`]);
	const tileset = await (await fetch(`/${name}.json`, { cache: 'no-store' })).json();
	scene = createScene({ walls, flats, sheet, tileset, width: screen.width, height: screen.height });
	animSelect.replaceChildren(...scene.animations.map((id) => new Option(id, id)));
	const wanted = params.get('anim');
	if (wanted && scene.animations.includes(wanted)) {
		animSelect.value = wanted;
		scene.setAnimation(wanted);
	}
}

sheetInput.addEventListener('change', () => load(sheetInput.value).catch(showError));
animSelect.addEventListener('change', () => scene?.setAnimation(animSelect.value));
addEventListener('keydown', (e) => keys.add(e.key));
addEventListener('keyup', (e) => keys.delete(e.key));

function showError(e) {
	readout.textContent = `erreur : ${e}`;
	console.error(e);
}

let previous = performance.now();
function frame(now) {
	const dt = Math.min(now - previous, 100);
	previous = now;
	if (scene) {
		if (keys.has('ArrowLeft')) orbit -= dt * 0.002;
		if (keys.has('ArrowRight')) orbit += dt * 0.002;
		if (keys.has('ArrowUp')) distance = Math.max(0.8, distance - dt * 0.003);
		if (keys.has('ArrowDown')) distance = Math.min(5.5, distance + dt * 0.003);
		if (spin.checked) orbit += dt * 0.0005;
		scene.animate(dt);
		const d = scene.render(orbit, distance);
		target.drawImage(scene.renderer.renderCanvas, 0, 0);
		readout.textContent = `direction ${d}`;
	}
	requestAnimationFrame(frame);
}

load(sheetInput.value).catch(showError);
requestAnimationFrame(frame);
