import { defineConfig } from 'vite';

// The sheets made by tools/sprites.py are served from the site root.
export default defineConfig({
	publicDir: '../output',
	server: {
		fs: { allow: ['..', '../../raycaster-386'] },
	},
});
