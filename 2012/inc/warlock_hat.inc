#declare HatTop = sphere_sweep {
  linear_spline
  3
  <0, 0, 0>, 1
  <0, 1, 0>, 0.5
  <0, 2, 1>, 0.1
}

#declare HatTopClipped = intersection {
  object {
    HatTop
  }
  box {
    <-10, 0.2, -10>
    <10, 10, 10>
  }
}

#declare HatBase = lathe {
  linear_spline
  5
  <0, 0>
  <2, 0>
  <2, 0.25>
  <1, 0.5>
  <0, 0.5>
}

#declare Hat = union {
  object {
    HatTopClipped
    translate 0.3 * y
  }
  object {
    HatBase
  }
  pigment {
    HatColor
  } 
  rotate <0, 35, 0>
  rotate <15, 0, 0>
}

