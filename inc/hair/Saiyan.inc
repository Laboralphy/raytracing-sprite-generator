#declare P_Saiyan_Spike = cone {
  0
  0.2
  <0, 1.5, 0>
  0
}

#declare P_Saiyan_Spikes = union {
  object {
    P_Saiyan_Spike
  }
  object {
    P_Saiyan_Spike
    rotate <-7, 0, 0>
  }
  object {
    P_Saiyan_Spike
    rotate <-14, 0, 0>
  }
  object {
    P_Saiyan_Spike
    rotate <7, 0, 0>
  }
  object {
    P_Saiyan_Spike
    rotate <14, 0, 0>
  }
  object {
    P_Saiyan_Spike
    rotate <21, 0, 0>
  }
  object {
    P_Saiyan_Spike
    rotate <28, 0, 0>
  }
  object {
    P_Saiyan_Spike
    rotate <35, 0, 0>
  }
  object {
    P_Saiyan_Spike
    rotate <42, 0, 0>
  }
  object {
    P_Saiyan_Spike
    rotate <49, 0, 0>
  }
}

#declare P_Saiyan_Forest = union {
  object {
    P_Saiyan_Spikes
  }
  object {
    P_Saiyan_Spikes
    scale 0.9
    rotate <0, 0, 7>
  }
  object {
    P_Saiyan_Spikes
    scale 0.9
    rotate <0, 0, -7>
  }
  object {
    P_Saiyan_Spikes
    scale 0.8
    rotate <0, 0, 14>
  }
  object {
    P_Saiyan_Spikes
    scale 0.8
    rotate <0, 0, -14>
  }
  object {
    P_Saiyan_Spikes
    scale 0.7
    rotate <0, 0, 21>
  }
  object {
    P_Saiyan_Spikes
    scale 0.7
    rotate <0, 0, -21>
  }
  object {
    P_Saiyan_Spikes
    scale 0.7
    rotate <0, 35, 0>
  }
  object {
    P_Saiyan_Spikes
    scale 0.7
    rotate <0, -35, 0>
  }
}