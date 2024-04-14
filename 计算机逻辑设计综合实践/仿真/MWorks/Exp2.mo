within ;
model Exp2
  import Modelica.Units.SI;
  import D = Modelica.Electrical.Digital;
  import L = Modelica.Electrical.Digital.Interfaces.Logic;
  LogicDesignSimulation.chip_74LS.chip_74LS00.chip_74LS00 chip_74LS1
    annotation (Placement(transformation(origin = {-38.0, -34.0}, 
      extent = {{-10.0, -10.0}, {10.0, 10.0}})));
  LogicDesignSimulation.chip_74LS.chip_74LS86.chip_74LS86 chip_74LS87
    annotation (Placement(transformation(origin = {27.0, -12.0}, 
      extent = {{-10.0, -10.0}, {10.0, 10.0}})));
  LogicDesignSimulation.chip_74LS.chip_74LS153.chip_74LS153 chip_74LS154
    annotation (Placement(transformation(origin = {-22.0, 22.0}, 
      extent = {{-10.0, -10.0}, {10.0, 10.0}})));
  Modelica.Electrical.Digital.Sources.Set A "Digital Set Source" 
    annotation (Placement(transformation(origin = {-95.0, 45.0}, 
      extent = {{-10.0, -10.0}, {10.0, 10.0}})));
  LogicDesignSimulation.chip_74LS.utils.OutNode WE1
    annotation (Placement(transformation(origin = {89.0, 26.0}, 
      extent = {{-10.0, -10.0}, {10.0, 10.0}})));
  LogicDesignSimulation.chip_74LS.utils.OutNode WE2
    annotation (Placement(transformation(origin = {90.0, -30.0}, 
      extent = {{-10.0, -10.0}, {10.0, 10.0}})));
  Modelica.Electrical.Digital.Sources.Set B
    annotation (Placement(transformation(origin = {-95.0, 3.0}, 
      extent = {{-10.0, -10.0}, {10.0, 10.0}})));
  Modelica.Electrical.Digital.Sources.Set C
    annotation (Placement(transformation(origin = {-95.0, -33.0}, 
      extent = {{-10.0, -10.0}, {10.0, 10.0}})));
  Modelica.Electrical.Digital.Sources.Set Ignore "Digital Set Source" 
    annotation (Placement(transformation(origin = {-94.5, 79.55882352941177}, 
      extent = {{-10.0, -10.0}, {10.0, 10.0}})));
equation 
  connect(A.y, chip_74LS154.S_0)
    annotation (Line(origin = {0.0, 0.0}, 
      points = {{-84.0, 44.0}, {-25.0, 44.0}, {-25.0, 31.0}}));
  connect(B.y, chip_74LS154.S_1)
    annotation (Line(origin = {0.0, 0.0}, 
      points = {{-84.0, 2.0}, {-28.0, 2.0}, {-28.0, 12.0}}));
  connect(C.y, chip_74LS1.A_1)
    annotation (Line(origin = {0.0, 0.0}, 
      points = {{-85.0, -33.0}, {-66.0, -33.0}, {-66.0, -30.0}, {-47.0, -30.0}, {-47.0, -29.0}}));
  connect(C.y, chip_74LS1.B_1)
    annotation (Line(origin = {0.0, 0.0}, 
      points = {{-85.0, -33.0}, {-47.0, -33.0}}));
  connect(chip_74LS1.Y_1, chip_74LS154.C2_1)
    annotation (Line(origin = {0.0, 0.0}, 
      points = {{-47.0, -36.0}, {-61.0, -36.0}, {-61.0, -2.0}, {-23.0, -2.0}, {-23.0, 12.0}}));
  connect(chip_74LS1.Y_1, chip_74LS154.C1_1)
    annotation (Line(origin = {0.0, 0.0}, 
      points = {{-47.0, -36.0}, {-61.0, -36.0}, {-61.0, -2.0}, {-21.0, -2.0}, {-21.0, 12.0}, {-20.0, 12.0}}));
  connect(C.y, chip_74LS154.C3_1)
    annotation (Line(origin = {0.0, 0.0}, 
      points = {{-85.0, -33.0}, {-72.0, -33.0}, {-72.0, -8.0}, {-26.0, -8.0}, {-26.0, 12.0}, {-25.0, 12.0}}));
  connect(C.y, chip_74LS154.C0_1)
    annotation (Line(origin = {0.0, 0.0}, 
      points = {{-85.0, -33.0}, {-72.0, -33.0}, {-72.0, -8.0}, {-18.0, -8.0}, {-18.0, 12.0}}));
  connect(chip_74LS1.Y_1, chip_74LS154.C2_2)
    annotation (Line(origin = {0.0, 0.0}, 
      points = {{-47.0, -36.0}, {-61.0, -36.0}, {-61.0, 38.0}, {-21.0, 38.0}, {-21.0, 32.0}, {-20.0, 32.0}, {-20.0, 31.0}}));
  connect(chip_74LS1.Y_1, chip_74LS154.C1_2)
    annotation (Line(origin = {0.0, 0.0}, 
      points = {{-47.0, -36.0}, {-61.0, -36.0}, {-61.0, 38.0}, {-18.0, 38.0}, {-18.0, 31.0}}));
  connect(C.y, chip_74LS154.C3_2)
    annotation (Line(origin = {0.0, 0.0}, 
      points = {{-85.0, -33.0}, {-72.0, -33.0}, {-72.0, 41.0}, {-23.0, 41.0}, {-23.0, 31.0}}));
  connect(C.y, chip_74LS154.C0_2)
    annotation (Line(origin = {0.0, 0.0}, 
      points = {{-85.0, -33.0}, {-72.0, -33.0}, {-72.0, 41.0}, {-16.0, 41.0}, {-16.0, 32.0}, {-15.0, 32.0}, {-15.0, 31.0}}));
  connect(chip_74LS154.F_1, chip_74LS1.B_3)
    annotation (Line(origin = {0.0, 0.0}, 
      points = {{-15.0, 12.0}, {-16.0, 12.0}, {-16.0, -28.0}, {-27.0, -28.0}}));
  connect(chip_74LS1.A_3, chip_74LS154.F_1)
    annotation (Line(origin = {0.0, 0.0}, 
      points = {{-27.0, -31.0}, {-15.0, -31.0}, {-15.0, 12.0}}));
  connect(chip_74LS1.Y_3, chip_74LS87.A_1)
    annotation (Line(origin = {0.0, 0.0}, 
      points = {{-27.0, -35.0}, {19.0, -35.0}, {19.0, -22.0}}));
  connect(chip_74LS154.F_2, chip_74LS87.B_1)
    annotation (Line(origin = {0.0, 0.0}, 
      points = {{-12.0, 31.0}, {2.0, 31.0}, {2.0, -28.0}, {23.0, -28.0}, {23.0, -22.0}, {22.0, -22.0}, {22.0, -21.0}}));
  connect(chip_74LS154.F_1, WE1.x)
    annotation (Line(origin = {0.0, 0.0}, 
      points = {{-15.0, 12.0}, {32.0, 12.0}, {32.0, 26.0}, {79.0, 26.0}, {79.0, 25.0}}));
  connect(chip_74LS87.Y_1, WE2.x)
    annotation (Line(origin = {0.0, 0.0}, 
      points = {{25.0, -21.0}, {25.0, -30.0}, {80.0, -30.0}}));
  connect(Ignore.y, chip_74LS154.Vcc)
    annotation (Line(origin = {0.0, 0.0}, 
      points = {{-84.0, 79.0}, {-30.0, 79.0}, {-30.0, 31.0}}));
  connect(Ignore.y, chip_74LS154.G_2)
    annotation (Line(origin = {0.0, 0.0}, 
      points = {{-84.0, 79.0}, {-28.0, 79.0}, {-28.0, 31.0}}));
  connect(Ignore.y, chip_74LS87.Vcc)
    annotation (Line(origin = {0.0, 0.0}, 
      points = {{-84.0, 79.0}, {18.0, 79.0}, {18.0, -1.0}}));
  connect(Ignore.y, chip_74LS87.B_4)
    annotation (Line(origin = {0.0, 0.0}, 
      points = {{-84.0, 79.0}, {21.0, 79.0}, {21.0, -1.0}}));
  connect(Ignore.y, chip_74LS154.G_1)
    annotation (Line(origin = {0.0, 0.0}, 
      points = {{-84.0, 79.0}, {-51.0, 79.0}, {-51.0, 6.0}, {-31.0, 6.0}, {-31.0, 12.0}, {-30.0, 12.0}}));
  connect(Ignore.y, chip_74LS154.GND)
    annotation (Line(origin = {0.0, 0.0}, 
      points = {{-84.0, 79.0}, {-51.0, 79.0}, {-51.0, 6.0}, {-13.0, 6.0}, {-13.0, 12.0}, {-12.0, 12.0}}));
  connect(Ignore.y, chip_74LS87.B_3)
    annotation (Line(origin = {0.0, 0.0}, 
      points = {{-84.0, 79.0}, {29.0, 79.0}, {29.0, -1.0}}));
  connect(Ignore.y, chip_74LS87.A_3)
    annotation (Line(origin = {0.0, 0.0}, 
      points = {{-84.0, 79.0}, {32.0, 79.0}, {32.0, -1.0}}));
  connect(Ignore.y, chip_74LS87.A_2)
    annotation (Line(origin = {0.0, 0.0}, 
      points = {{-84.0, 79.0}, {8.0, 79.0}, {8.0, -32.0}, {27.0, -32.0}, {27.0, -22.0}}));
  connect(Ignore.y, chip_74LS87.B_2)
    annotation (Line(origin = {0.0, 0.0}, 
      points = {{-84.0, 79.0}, {8.0, 79.0}, {8.0, -32.0}, {30.0, -32.0}, {30.0, -22.0}, {29.0, -22.0}}));
  connect(Ignore.y, chip_74LS87.GND)
    annotation (Line(origin = {0.0, 0.0}, 
      points = {{-84.0, 79.0}, {8.0, 79.0}, {8.0, -32.0}, {35.0, -32.0}, {35.0, -21.0}}));
  connect(Ignore.y, chip_74LS87.A_4)
    annotation (Line(origin = {0.0, 0.0}, 
      points = {{-84.0, 79.0}, {24.0, 79.0}, {24.0, -1.0}}));
  connect(Ignore.y, chip_74LS1.Vcc)
    annotation (Line(origin = {0.0, 0.0}, 
      points = {{-84.0, 79.0}, {-45.0, 79.0}, {-45.0, -23.0}}));
  connect(Ignore.y, chip_74LS1.B_4)
    annotation (Line(origin = {0.0, 0.0}, 
      points = {{-84.0, 79.0}, {-40.0, 79.0}, {-40.0, -23.0}}));
  connect(Ignore.y, chip_74LS1.A_4)
    annotation (Line(origin = {0.0, 0.0}, 
      points = {{-84.0, 79.0}, {-36.0, 79.0}, {-36.0, -23.0}}));
  connect(Ignore.y, chip_74LS1.A_2)
    annotation (Line(origin = {0.0, 0.0}, 
      points = {{-84.0, 79.0}, {-67.0, 79.0}, {-67.0, -53.0}, {-45.0, -53.0}, {-45.0, -44.0}, {-44.0, -44.0}, {-44.0, -43.0}}));
  connect(Ignore.y, chip_74LS1.B_2)
    annotation (Line(origin = {0.0, 0.0}, 
      points = {{-84.0, 79.0}, {-67.0, 79.0}, {-67.0, -53.0}, {-40.0, -53.0}, {-40.0, -44.0}, {-39.0, -44.0}}));
  connect(Ignore.y, chip_74LS1.GND)
    annotation (Line(origin = {0.0, 0.0}, 
      points = {{-84.0, 79.0}, {-67.0, 79.0}, {-67.0, -53.0}, {-32.0, -53.0}, {-32.0, -44.0}, {-31.0, -44.0}}));
end Exp2;