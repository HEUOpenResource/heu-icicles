within ;
model Exp3
  import Modelica.Units.SI;
  import D = Modelica.Electrical.Digital;
  import L = Modelica.Electrical.Digital.Interfaces.Logic;
  LogicDesignSimulation.chip_74LS.chip_74LS00.chip_74LS00 chip_74LS00_1
    annotation (Placement(transformation(origin = {-53.0, 50.0}, 
      extent = {{-28.0, -28.0}, {28.0, 28.0}})));
  LogicDesignSimulation.chip_74LS.chip_74LS86.chip_74LS86 chip_74LS86_1
    annotation (Placement(transformation(origin = {-50.94427813802346, -50.0}, 
      extent = {{-27.999999999999915, -28.0}, {28.000000000000085, 28.0}})));
  Modelica.Electrical.Digital.Sources.Set Y3(x = L.'0')
    annotation (Placement(transformation(origin = {-144.0, 59.77140820503023}, 
      extent = {{-10.0, -10.0}, {10.0, 10.0}})));
  Modelica.Electrical.Digital.Sources.Set Y2
    annotation (Placement(transformation(origin = {-144.0, 24.0}, 
      extent = {{-10.0, -10.0}, {10.0, 10.0}})));
  Modelica.Electrical.Digital.Sources.Set Y1
    annotation (Placement(transformation(origin = {-144.0, -11.771408205030227}, 
      extent = {{-10.0, -10.0}, {10.0, 10.0}})));
  Modelica.Electrical.Digital.Sources.Set Y0(x = L.'0')
    annotation (Placement(transformation(origin = {-144.0, -47.542816410060446}, 
      extent = {{-10.0, -10.0}, {10.0, 10.0}})));
  Modelica.Electrical.Digital.Sources.Set VCC
    annotation (Placement(transformation(origin = {-144.0, 95.54281641006045}, 
      extent = {{-10.0, -10.0}, {10.0, 10.0}})));
  LogicDesignSimulation.chip_74LS.utils.OutNode B3
    annotation (Placement(transformation(origin = {52.0, 41.291506225278404}, 
      extent = {{-10.0, -10.0}, {10.0, 10.0}})));
  LogicDesignSimulation.chip_74LS.utils.OutNode B2
    annotation (Placement(transformation(origin = {52.0, 8.583012450556787}, 
      extent = {{-10.0, -10.0}, {10.0, 10.0}})));
  LogicDesignSimulation.chip_74LS.utils.OutNode B1
    annotation (Placement(transformation(origin = {52.0, -20.708493774721596}, 
      extent = {{-10.0, -10.0}, {10.0, 10.0}})));
  LogicDesignSimulation.chip_74LS.utils.OutNode B0
    annotation (Placement(transformation(origin = {52.0, -49.99999999999999}, 
      extent = {{-10.0, -10.0}, {10.0, 10.0}})));
equation 
  connect(Y0.y, chip_74LS86_1.B_4)
    annotation (Line(origin = {-100.0, -34.0}, 
      points = {{-34.0, -14.0}, {10.0, -14.0}, {10.0, 20.0}, {33.0, 20.0}, {33.0, 13.0}}, 
      color = {127, 0, 127}));
  connect(Y0.y, chip_74LS00_1.B_4)
    annotation (Line(origin = {-79.0, 8.0}, 
      points = {{-55.0, -56.0}, {-12.0, -56.0}, {-12.0, -4.0}, {64.0, -4.0}, {64.0, 80.0}, {19.0, 80.0}, {19.0, 71.0}}, 
      color = {127, 0, 127}));
  connect(Y0.y, chip_74LS86_1.B_3)
    annotation (Line(origin = {-89.0, -35.0}, 
      points = {{-45.0, -13.0}, {-2.0, -13.0}, {-2.0, 22.0}, {45.0, 22.0}, {45.0, 13.0}}, 
      color = {127, 0, 127}));
  connect(Y1.y, chip_74LS86_1.A_3)
    annotation (Line(origin = {-85.0, -17.0}, 
      points = {{-49.0, 5.0}, {49.0, 5.0}, {49.0, -5.0}}, 
      color = {127, 0, 127}));
  connect(Y1.y, chip_74LS00_1.A_4)
    annotation (Line(origin = {-79.0, 21.0}, 
      points = {{-55.0, -33.0}, {-55.0, -32.0}, {66.0, -32.0}, {66.0, 64.0}, {31.0, 64.0}, {31.0, 58.0}}, 
      color = {127, 0, 127}));
  connect(Y2.y, chip_74LS86_1.A_2)
    annotation (Line(origin = {-92.0, -27.0}, 
      points = {{-42.0, 51.0}, {-42.0, 50.0}, {-4.0, 50.0}, {-4.0, -64.0}, {42.0, -64.0}, {42.0, -51.0}}, 
      color = {127, 0, 127}));
  connect(Y2.y, chip_74LS00_1.B_3)
    annotation (Line(origin = {-79.0, 44.0}, 
      points = {{-55.0, -20.0}, {-18.0, -20.0}, {-18.0, -38.0}, {68.0, -38.0}, {68.0, 19.0}, {54.0, 19.0}}, 
      color = {127, 0, 127}));
  connect(VCC.y, chip_74LS00_1.A_3)
    annotation (Line(origin = {-79.0, 75.0}, 
      points = {{-55.0, 21.0}, {70.0, 21.0}, {70.0, -22.0}, {54.0, -22.0}}, 
      color = {127, 0, 127}));
  connect(Y3.y, chip_74LS00_1.A_1)
    annotation (Line(origin = {-107.0, 60.0}, 
      points = {{-27.0, 0.0}, {26.0, 0.0}}, 
      color = {127, 0, 127}));
  connect(chip_74LS00_1.Y_3, chip_74LS00_1.A_2)
    annotation (Line(origin = {-47.0, 31.0}, 
      points = {{22.0, 11.0}, {30.0, 11.0}, {30.0, -24.0}, {-25.0, -24.0}, {-25.0, -9.0}}, 
      color = {127, 0, 127}));
  connect(chip_74LS00_1.Y_4, chip_74LS00_1.B_2)
    annotation (Line(origin = {-40.0, 50.0}, 
      points = {{2.0, 29.0}, {6.0, 29.0}, {6.0, 30.0}, {22.0, 30.0}, {22.0, -40.0}, {-18.0, -40.0}, {-18.0, -28.0}}, 
      color = {127, 0, 127}));
  connect(chip_74LS00_1.Y_4, chip_74LS86_1.B_2)
    annotation (Line(origin = {-40.0, 1.0}, 
      points = {{2.0, 78.0}, {34.0, 78.0}, {34.0, -94.0}, {-3.0, -94.0}, {-3.0, -79.0}}, 
      color = {127, 0, 127}));
  connect(chip_74LS86_1.A_1, VCC.y)
    annotation (Line(origin = {-104.0, 9.0}, 
      points = {{30.0, -87.0}, {30.0, -98.0}, {6.0, -98.0}, {6.0, 87.0}, {-30.0, 87.0}}, 
      color = {127, 0, 127}));
  connect(chip_74LS00_1.Y_1, chip_74LS86_1.B_1)
    annotation (Line(origin = {-73.0, -19.0}, 
      points = {{-8.0, 58.0}, {-28.0, 58.0}, {-28.0, -68.0}, {7.0, -68.0}, {7.0, -59.0}}, 
      color = {127, 0, 127}));
  connect(chip_74LS86_1.A_4, VCC.y)
    annotation (Line(origin = {-96.0, 38.0}, 
      points = {{37.0, -59.0}, {37.0, -54.0}, {-8.0, -54.0}, {-8.0, 58.0}, {-38.0, 58.0}}, 
      color = {127, 0, 127}));
  connect(chip_74LS00_1.B_1, chip_74LS00_1.Y_2)
    annotation (Line(origin = {-63.0, 36.0}, 
      points = {{-18.0, 14.0}, {-30.0, 14.0}, {-30.0, -22.0}, {17.0, -22.0}, {17.0, -15.0}}, 
      color = {127, 0, 127}));
  connect(chip_74LS86_1.Y_1, B3.x)
    annotation (Line(origin = {-7.0, -18.0}, 
      points = {{-50.0, -60.0}, {-50.0, -78.0}, {8.0, -78.0}, {8.0, 59.0}, {49.0, 59.0}}, 
      color = {127, 0, 127}));
  connect(chip_74LS86_1.Y_2, B2.x)
    annotation (Line(origin = {4.0, -36.0}, 
      points = {{-38.0, -42.0}, {-38.0, -54.0}, {0.0, -54.0}, {0.0, 44.0}, {38.0, 44.0}}, 
      color = {127, 0, 127}));
  connect(chip_74LS86_1.Y_3, B1.x)
    annotation (Line(origin = {7.0, -20.0}, 
      points = {{-35.0, -1.0}, {-31.0, -1.0}, {-31.0, 0.0}, {35.0, 0.0}, {35.0, -1.0}}, 
      color = {127, 0, 127}));
  connect(chip_74LS86_1.Y_4, B0.x)
    annotation (Line(origin = {-4.0, -35.0}, 
      points = {{-47.0, 13.0}, {-47.0, 20.0}, {2.0, 20.0}, {2.0, -15.0}, {46.0, -15.0}}, 
      color = {127, 0, 127}));
end Exp3;