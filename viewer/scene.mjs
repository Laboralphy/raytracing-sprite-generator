/**
 * A room with one sprite in the middle, shared by the browser viewer and the
 * headless snapshot.
 *
 * The sprite points along +x. A strip of different floor tiles runs from it
 * along +x, so from any viewpoint the character must be looking towards the
 * strip: that is what checks the direction order of a sheet.
 */
import {
	ANIM_LOOP_FORWARD,
	ANIM_LOOP_NONE,
	ANIM_LOOP_YOYO,
	MapHelper,
	PHYS_NONE,
	PHYS_WALL,
	Renderer,
	faceCamera,
} from '@laboralphy/raycaster386';

export const METRICS = { spacing: 64, height: 96 };
const SIZE = 13;
const CENTER = (SIZE >> 1) + 0.5;

/** Where the sprite stands and where it points, in world units and radians. */
export const SPRITE = { x: CENTER * METRICS.spacing, y: CENTER * METRICS.spacing, facing: 0 };

const LOOPS = {
	'@LOOP_NONE': ANIM_LOOP_NONE,
	'@LOOP_FORWARD': ANIM_LOOP_FORWARD,
	'@LOOP_YOYO': ANIM_LOOP_YOYO,
};

function buildLevel() {
	const map = [];
	for (let y = 0; y < SIZE; ++y) {
		let row = '';
		for (let x = 0; x < SIZE; ++x) {
			const border = x === 0 || y === 0 || x === SIZE - 1 || y === SIZE - 1;
			const strip = y === SIZE >> 1 && x > SIZE >> 1 && !border;
			row += border ? '#' : strip ? '=' : ' ';
		}
		map.push(row);
	}
	return {
		legend: [
			{ code: ' ', phys: PHYS_NONE, faces: { f: 0, c: 1 } },
			{ code: '#', phys: PHYS_WALL, faces: { n: 0, e: 0, w: 0, s: 0 } },
			// The marker strip: the ceiling tile used as floor.
			{ code: '=', phys: PHYS_NONE, faces: { f: 1, c: 1 } },
		],
		map,
	};
}

/**
 * @param walls, flats decoded wall and flat atlases (canvases)
 * @param sheet decoded sprite sheet (canvas)
 * @param tileset the tileset fragment written by tools/sprites.py
 */
export function createScene({ walls, flats, sheet, tileset, width = 320, height = 200 }) {
	const rc = new Renderer();
	rc.setMetrics(METRICS);
	rc.setShading({ shades: 16, color: '#000000', filter: null, brightness: 0.4 });
	rc.setScreen({ width, height });
	rc.setWallTextures(walls);
	rc.setFlatTextures(flats);
	new MapHelper().build(rc, buildLevel());

	const ts = rc.buildTileSet(sheet, tileset.width, tileset.height);
	const sprite = rc.buildSprite(ts);
	for (const a of tileset.animations) {
		sprite.buildAnimation(
			{
				starts: Array.isArray(a.start) ? a.start : [a.start],
				length: a.length,
				duration: a.duration,
				loop: LOOPS[a.loop] ?? ANIM_LOOP_FORWARD,
			},
			a.id
		);
	}
	// Without a current group, Sprite.facings is 0 and faceCamera never turns the sprite.
	sprite.setCurrentAnimation(tileset.animations[0].id);
	sprite.x = SPRITE.x;
	sprite.y = SPRITE.y;

	return {
		renderer: rc,
		sprite,
		animations: tileset.animations.map((a) => a.id),
		setAnimation(id) {
			sprite.setCurrentAnimation(id);
		},
		/**
		 * Places the camera on a circle around the sprite, looking at it.
		 * @param orbit angle of the camera around the sprite, in radians
		 * @param distance in cells
		 * @returns the direction index the engine picked
		 */
		render(orbit, distance) {
			const r = distance * METRICS.spacing;
			const cx = SPRITE.x + Math.cos(orbit) * r;
			const cy = SPRITE.y + Math.sin(orbit) * r;
			const direction = faceCamera(sprite, SPRITE.facing, cx, cy);
			rc.render(cx, cy, orbit + Math.PI, 1);
			return direction;
		},
		animate(ms) {
			rc.computeAnimations(ms);
		},
	};
}

/** The camera orbit angle at which the engine shows direction `d` (sprite pointing along +x). */
export function orbitForDirection(d) {
	return Math.PI - (d * Math.PI) / 4;
}
