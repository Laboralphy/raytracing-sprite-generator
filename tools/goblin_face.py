# Goblin face, same layout as png/troll_face.png (spherical map, face around x = 390)
from PIL import Image, ImageDraw
W = 512
im = Image.new("RGBA", (W, W), (0, 0, 0, 0))
d = ImageDraw.Draw(im)
cx = 390
# eyes: dark socket, yellow iris, black slit
for ex in (cx - 48, cx + 48):
    d.ellipse((ex - 34, 140, ex + 34, 196), fill=(25, 30, 5, 255))
    d.ellipse((ex - 26, 146, ex + 26, 190), fill=(255, 210, 30, 255))
    d.ellipse((ex - 6, 148, ex + 6, 188), fill=(0, 0, 0, 255))
# angry brows, slanting down towards the nose
d.polygon([(cx - 90, 118), (cx - 14, 140), (cx - 18, 152), (cx - 92, 132)], fill=(20, 30, 5, 255))
d.polygon([(cx + 90, 118), (cx + 14, 140), (cx + 18, 152), (cx + 92, 132)], fill=(20, 30, 5, 255))
# wide grin
mouth = [(cx - 95, 255), (cx - 50, 290), (cx, 300), (cx + 50, 290), (cx + 95, 255),
         (cx + 60, 320), (cx, 335), (cx - 60, 320)]
d.polygon(mouth, fill=(30, 5, 5, 255))
# pointed teeth, upper and lower
for i in range(-4, 5):
    x = cx + i * 18
    yt = 262 + abs(i) ** 1.6 * 3 + 20 - abs(i) * 4
    d.polygon([(x - 8, yt), (x + 8, yt), (x, yt + 18)], fill=(235, 225, 170, 255))
for i in range(-3, 4):
    x = cx + 9 + i * 18
    yb = 322 - abs(i) * 4
    d.polygon([(x - 7, yb), (x + 7, yb), (x, yb - 15)], fill=(235, 225, 170, 255))
im.save("png/goblin_face.png")
