#declare KnifeBlade = object {
  cone {
    <0, 0, 0>
    0.25
    <0, 1.25, 0>
    0
  }
  scale <1, 1, 0.1>
}

#declare KnifeGarde = object {
  cylinder {
    <0, 0, 0>
    <0, 0.25, 0>
    0.5
  }
  scale <1, 1, 0.1>
}

#declare KnifeHandle = object {
  cylinder {
    <0, 0, 0>
    <0, 0.5, 0>
    0.125
  }
}

#declare Knife = union {
  object {
    KnifeHandle
    translate -0.5 * y
    pigment {
      color rgb <0, 0, 0>
    }
  }
  object {
    KnifeGarde
    pigment {
      color rgb <0, 0, 0>
    }
  }
  object {
    KnifeBlade
    translate 0.25 * y
    pigment {
      color rgb <1, 0.8, 0.8>
    }
  }
}

