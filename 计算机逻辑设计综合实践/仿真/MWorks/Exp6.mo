within ;
model Exp6
  import Modelica.Units.SI;
  import D = Modelica.Electrical.Digital;
  import L = Modelica.Electrical.Digital.Interfaces.Logic;
  LogicDesignSimulation.chip_74LS.chip_74LS00.chip_74LS00 chip_74LS00_1
    annotation (Placement(transformation(origin = {-49.99999999999999, 50.0}, 
      extent = {{-28.0, -28.0}, {28.0, 28.0}})));
  LogicDesignSimulation.chip_74LS.chip_74LS20.chip_74LS20 chip_74LS20_1
    annotation (Placement(transformation(origin = {50.0, 50.0}, 
      extent = {{-28.0, -27.999999999999993}, {28.0, 28.0}})));
  LogicDesignSimulation.chip_74LS.chip_74LS74.chip_74LS74 chip_74LS74_1
    annotation (Placement(transformation(origin = {-49.99999999999999, -49.99999999999999}, 
      extent = {{-28.0, -28.0}, {27.999999999999986, 28.0}})));
  Modelica.Electrical.Digital.Sources.Pulse pulse
    annotation (Placement(transformation(origin = {-112.0, 0.0}, 
      extent = {{-10.0, -10.0}, {10.0, 10.0}})));
  Modelica.Electrical.Digital.Sources.Pulse x(period = 2) annotation (Placement(transformation(origin = {-124.0, -44.0}, 
    extent = {{-10.0, -10.0}, {10.0, 10.0}})));

  Modelica.Electrical.Digital.Sources.Set VCC
    annotation (Placement(transformation(origin = {-112.0, 120.0}, 
      extent = {{-10.0, -10.0}, {10.0, 10.0}})));
  LogicDesignSimulation.chip_74LS.utils.OutNode F
    annotation (Placement(transformation(origin = {119.99999999999999, 110.0}, 
      extent = {{-10.0, -10.0}, {10.0, 10.0}})));
  LogicDesignSimulation.chip_74LS.utils.OutNode Q1
    annotation (Placement(transformation(origin = {31.999999999999993, 152.0}, 
      extent = {{-10.0, -10.0}, {10.0, 10.0}})));
  LogicDesignSimulation.chip_74LS.utils.OutNode Q0
    annotation (Placement(transformation(origin = {68.0, 152.0}, 
      extent = {{-10.0, -10.0}, {10.0, 10.0}})));
equation 
  connect(pulse.y, chip_74LS74_1.CK_2)
    annotation (Line(origin = {-76.0, -11.0}, 
      points = {{-26.0, 11.0}, {25.0, 11.0}, {25.0, -12.0}}, 
      color = {127, 0, 127}));
  connect(pulse.y, chip_74LS74_1.CK_1)
    annotation (Line(origin = {-80.0, -39.0}, 
      points = {{-22.0, 39.0}, {-22.0, -50.0}, {21.0, -50.0}, {21.0, -39.0}}, 
      color = {127, 0, 127}));
  connect(x.y, chip_74LS74_1.D_1)
    annotation (Line(origin = {-90.0, -61.0}, 
      points = {{-24.0, 17.0}, {-18.0, 17.0}, {-18.0, -32.0}, {23.0, -32.0}, {23.0, -17.0}}, 
      color = {127, 0, 127}));
  connect(x.y, chip_74LS00_1.A_1)
    annotation (Line(origin = {-96.0, 8.0}, 
      points = {{-18.0, -52.0}, {-2.0, -52.0}, {-2.0, 52.0}, {18.0, 52.0}}, 
      color = {127, 0, 127}));
  connect(x.y, chip_74LS00_1.A_3)
    annotation (Line(origin = {-68.0, 5.0}, 
      points = {{-46.0, -49.0}, {-46.0, -104.0}, {64.0, -104.0}, {64.0, 48.0}, {46.0, 48.0}}, 
      color = {127, 0, 127}));
  connect(VCC.y, chip_74LS00_1.B_3)
    annotation (Line(origin = {-62.0, 92.0}, 
      points = {{-40.0, 28.0}, {58.0, 28.0}, {58.0, -29.0}, {40.0, -29.0}}, 
      color = {127, 0, 127}));
  connect(VCC.y, chip_74LS00_1.B_4)
    annotation (Line(origin = {-79.0, 100.0}, 
      points = {{-23.0, 20.0}, {22.0, 20.0}, {22.0, -21.0}}, 
      color = {127, 0, 127}));
  connect(VCC.y, chip_74LS20_1.D_1)
    annotation (Line(origin = {-22.0, 71.0}, 
      points = {{-80.0, 49.0}, {120.0, 49.0}, {120.0, -72.0}, {80.0, -72.0}, {80.0, -49.0}}, 
      color = {127, 0, 127}));
  connect(chip_74LS20_1.Y_1, chip_74LS00_1.A_4)
    annotation (Line(origin = {11.0, 50.0}, 
      points = {{56.0, -28.0}, {56.0, -48.0}, {-10.0, -48.0}, {-10.0, 64.0}, {-56.0, 64.0}, {-56.0, 29.0}}, 
      color = {127, 0, 127}));
  connect(chip_74LS00_1.Y_4, F.x)
    annotation (Line(origin = {38.0, 95.0}, 
      points = {{-73.0, -16.0}, {-72.0, -16.0}, {-72.0, 14.0}, {72.0, 14.0}, {72.0, 15.0}}, 
      color = {127, 0, 127}));
  connect(chip_74LS74_1.Q_2, Q0.x)
    annotation (Line(origin = {13.0, 65.0}, 
      points = {{-46.0, -88.0}, {-46.0, -66.0}, {-8.0, -66.0}, {-8.0, 60.0}, {38.0, 60.0}, {38.0, 87.0}, {45.0, 87.0}}, 
      color = {127, 0, 127}));
  connect(chip_74LS74_1.Q_1, Q1.x)
    annotation (Line(origin = {-10.0, 37.0}, 
      points = {{-32.0, -115.0}, {-32.0, -132.0}, {2.0, -132.0}, {2.0, 115.0}, {32.0, 115.0}}, 
      color = {127, 0, 127}));
  connect(chip_74LS74_1.Q_1, chip_74LS20_1.B_1)
    annotation (Line(origin = {-3.0, -28.0}, 
      points = {{-39.0, -50.0}, {-39.0, -68.0}, {38.0, -68.0}, {38.0, 50.0}}, 
      color = {127, 0, 127}));
  connect(chip_74LS74_1.QB_1, chip_74LS00_1.A_2)
    annotation (Line(origin = {-51.0, -28.0}, 
      points = {{17.0, -50.0}, {17.0, -64.0}, {40.0, -64.0}, {40.0, 30.0}, {-18.0, 30.0}, {-18.0, 50.0}}, 
      color = {127, 0, 127}));
  connect(chip_74LS00_1.Y_2, chip_74LS74_1.D_2)
    annotation (Line(origin = {-51.0, -1.0}, 
      points = {{8.0, 22.0}, {8.0, -2.0}, {-9.0, -2.0}, {-9.0, -22.0}}, 
      color = {127, 0, 127}));
  connect(chip_74LS00_1.Y_1, chip_74LS00_1.B_2)
    annotation (Line(origin = {-66.0, 31.0}, 
      points = {{-12.0, 8.0}, {-30.0, 8.0}, {-30.0, -26.0}, {11.0, -26.0}, {11.0, -9.0}}, 
      color = {127, 0, 127}));
  connect(chip_74LS74_1.QB_2, chip_74LS00_1.B_1)
    annotation (Line(origin = {-51.0, 14.0}, 
      points = {{26.0, -37.0}, {26.0, -6.0}, {-42.0, -6.0}, {-42.0, 36.0}, {-27.0, 36.0}}, 
      color = {127, 0, 127}));
  connect(chip_74LS74_1.CLR_2, VCC.y)
    annotation (Line(origin = {-84.0, 49.0}, 
      points = {{17.0, -72.0}, {17.0, -52.0}, {-6.0, -52.0}, {-6.0, 71.0}, {-18.0, 71.0}}, 
      color = {127, 0, 127}));
  connect(chip_74LS74_1.PR_2, VCC.y)
    annotation (Line(origin = {-72.0, 49.0}, 
      points = {{30.0, -72.0}, {30.0, -56.0}, {-18.0, -56.0}, {-18.0, 71.0}, {-30.0, 71.0}}, 
      color = {127, 0, 127}));
  connect(chip_74LS74_1.CLR_1, VCC.y)
    annotation (Line(origin = {-88.0, 20.0}, 
      points = {{13.0, -97.0}, {13.0, -106.0}, {-2.0, -106.0}, {-2.0, 100.0}, {-14.0, 100.0}}, 
      color = {127, 0, 127}));
  connect(chip_74LS74_1.PR_1, VCC.y)
    annotation (Line(origin = {-76.0, 20.0}, 
      points = {{25.0, -98.0}, {25.0, -106.0}, {-14.0, -106.0}, {-14.0, 100.0}, {-26.0, 100.0}}, 
      color = {127, 0, 127}));
  connect(chip_74LS00_1.Y_3, chip_74LS20_1.C_1)
    annotation (Line(origin = {15.0, 32.0}, 
      points = {{-37.0, 10.0}, {-6.0, 10.0}, {-6.0, -28.0}, {36.0, -28.0}, {36.0, -10.0}}, 
      color = {127, 0, 127}));
  connect(chip_74LS74_1.Q_2, chip_74LS20_1.A_1)
    annotation (Line(origin = {-3.0, 0.0}, 
      points = {{-30.0, -23.0}, {-30.0, -6.0}, {30.0, -6.0}, {30.0, 22.0}}, 
      color = {127, 0, 127}));
  connect(chip_74LS20_1.D_2, VCC.y)
    annotation (Line(origin = {-34.0, 100.0}, 
      points = {{68.0, -21.0}, {68.0, 20.0}, {-68.0, 20.0}}, 
      color = {127, 0, 127}));
  connect(chip_74LS20_1.C_2, VCC.y)
    annotation (Line(origin = {-30.0, 100.0}, 
      points = {{72.0, -21.0}, {72.0, 20.0}, {-72.0, 20.0}}, 
      color = {127, 0, 127}));
  connect(chip_74LS20_1.B_2, VCC.y)
    annotation (Line(origin = {-22.0, 99.0}, 
      points = {{79.0, -21.0}, {79.0, 21.0}, {-80.0, 21.0}}, 
      color = {127, 0, 127}));
  connect(chip_74LS20_1.A_2, VCC.y)
    annotation (Line(origin = {-18.0, 99.0}, 
      points = {{83.0, -21.0}, {83.0, 21.0}, {-84.0, 21.0}}, 
      color = {127, 0, 127}));
end Exp6;