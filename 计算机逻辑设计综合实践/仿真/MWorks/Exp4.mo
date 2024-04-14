within ;
model Exp4
  import Modelica.Units.SI;
  import D = Modelica.Electrical.Digital;
  import L = Modelica.Electrical.Digital.Interfaces.Logic;
  LogicDesignSimulation.chip_74LS.chip_74LS112.chip_74LS112 chip_74LS112_1
    annotation (Placement(transformation(origin = {-50.0, -48.0}, 
      extent = {{-30.0, -30.0}, {30.0, 30.0}})));
  LogicDesignSimulation.chip_74LS.chip_74LS112.chip_74LS112 chip_74LS112_2
    annotation (Placement(transformation(origin = {49.999999999999986, -48.0}, 
      extent = {{-30.0, -30.0}, {30.0, 30.0}})));
  LogicDesignSimulation.chip_74LS.chip_74LS00.chip_74LS00 chip_74LS00_1
    annotation (Placement(transformation(origin = {-50.16277120677114, 46.0}, 
      extent = {{-30.0, -29.999999999999993}, {29.999999999999993, 30.0}})));
  Modelica.Electrical.Digital.Sources.Pulse pulse
    annotation (Placement(transformation(origin = {-118.0, 0.0}, 
      extent = {{-10.0, -10.0}, {10.0, 10.0}})));
  Modelica.Electrical.Digital.Sources.Set VCC
    annotation (Placement(transformation(origin = {-110.0, 34.65135904430821}, 
      extent = {{-10.0, -10.0}, {10.0, 10.0}})));
  LogicDesignSimulation.chip_74LS.utils.OutNode Q3
    annotation (Placement(transformation(origin = {49.99999999999998, 98.0}, 
      extent = {{-10.0, -10.0}, {10.0, 10.0}})));
  LogicDesignSimulation.chip_74LS.utils.OutNode Q2
    annotation (Placement(transformation(origin = {49.99999999999998, 74.0}, 
      extent = {{-10.0, -10.0}, {10.0, 10.0}})));
  LogicDesignSimulation.chip_74LS.utils.OutNode Q1
    annotation (Placement(transformation(origin = {49.99999999999998, 49.5149710613162}, 
      extent = {{-10.0, -10.0}, {10.0, 10.0}})));
  LogicDesignSimulation.chip_74LS.utils.OutNode Q0
    annotation (Placement(transformation(origin = {49.99999999999997, 25.02994212263241}, 
      extent = {{-10.0, -10.0}, {10.0, 10.0}})));
equation 
  connect(pulse.y, chip_74LS112_1.CK_2)
    annotation (Line(origin = {-78.0, -9.0}, 
      points = {{-30.0, 9.0}, {24.0, 9.0}, {24.0, -10.0}}, 
      color = {127, 0, 127}));
  connect(pulse.y, chip_74LS112_1.CK_1)
    annotation (Line(origin = {-89.0, -38.0}, 
      points = {{-19.0, 38.0}, {4.0, 38.0}, {4.0, -39.0}, {12.0, -39.0}}, 
      color = {127, 0, 127}));
  connect(pulse.y, chip_74LS112_2.CK_2)
    annotation (Line(origin = {-28.0, -9.0}, 
      points = {{-80.0, 9.0}, {74.0, 9.0}, {74.0, -10.0}}, 
      color = {127, 0, 127}));
  connect(pulse.y, chip_74LS112_2.CK_1)
    annotation (Line(origin = {-39.0, -38.0}, 
      points = {{-69.0, 38.0}, {54.0, 38.0}, {54.0, -39.0}, {62.0, -39.0}}, 
      color = {127, 0, 127}));
  connect(chip_74LS112_1.Q_1, chip_74LS112_1.J_2)
    annotation (Line(origin = {-43.0, -48.0}, 
      points = {{-4.0, -29.0}, {-4.0, -50.0}, {32.0, -50.0}, {32.0, 44.0}, {4.0, 44.0}, {4.0, 29.0}}, 
      color = {127, 0, 127}));
  connect(chip_74LS112_1.QB_1, chip_74LS112_1.K_2)
    annotation (Line(origin = {-43.0, -48.0}, 
      points = {{4.0, -30.0}, {4.0, -50.0}, {32.0, -50.0}, {32.0, 44.0}, {-4.0, 44.0}, {-4.0, 29.0}}, 
      color = {127, 0, 127}));
  connect(chip_74LS112_1.Q_2, chip_74LS112_2.J_1)
    annotation (Line(origin = {8.0, -48.0}, 
      points = {{-31.0, 29.0}, {-14.0, 29.0}, {-14.0, -50.0}, {30.0, -50.0}, {30.0, -30.0}}, 
      color = {127, 0, 127}));
  connect(chip_74LS112_1.QB_2, chip_74LS112_2.K_1)
    annotation (Line(origin = {0.0, -78.0}, 
      points = {{-31.0, 0.0}, {-31.0, -20.0}, {31.0, -20.0}, {31.0, 0.0}}, 
      color = {127, 0, 127}));
  connect(chip_74LS112_2.Q_1, chip_74LS112_2.J_2)
    annotation (Line(origin = {57.0, -48.0}, 
      points = {{-4.0, -29.0}, {-4.0, -50.0}, {32.0, -50.0}, {32.0, 48.0}, {4.0, 48.0}, {4.0, 29.0}}, 
      color = {127, 0, 127}));
  connect(chip_74LS112_2.QB_1, chip_74LS112_2.K_2)
    annotation (Line(origin = {57.0, -48.0}, 
      points = {{4.0, -30.0}, {4.0, -50.0}, {32.0, -50.0}, {32.0, 48.0}, {-4.0, 48.0}, {-4.0, 29.0}}, 
      color = {127, 0, 127}));
  connect(chip_74LS112_2.Q_2, chip_74LS00_1.A_1)
    annotation (Line(origin = {-1.0, 19.0}, 
      points = {{78.0, -38.0}, {78.0, -16.0}, {-96.0, -16.0}, {-96.0, 37.0}, {-79.0, 37.0}}, 
      color = {127, 0, 127}));
  connect(chip_74LS112_2.QB_2, chip_74LS112_1.J_1)
    annotation (Line(origin = {4.0, -78.0}, 
      points = {{65.0, 0.0}, {65.0, -20.0}, {-66.0, -20.0}, {-66.0, 0.0}}, 
      color = {127, 0, 127}));
  connect(chip_74LS112_2.Q_1, chip_74LS00_1.B_1)
    annotation (Line(origin = {-13.0, -15.0}, 
      points = {{66.0, -62.0}, {24.0, -62.0}, {24.0, 18.0}, {-84.0, 18.0}, {-84.0, 61.0}, {-67.0, 61.0}}, 
      color = {127, 0, 127}));
  connect(chip_74LS00_1.Y_1, chip_74LS00_1.A_2)
    annotation (Line(origin = {-75.0, 26.0}, 
      points = {{-5.0, 9.0}, {-5.0, -10.0}, {5.0, -10.0}}, 
      color = {127, 0, 127}));
  connect(VCC.y, chip_74LS00_1.B_2)
    annotation (Line(origin = {-79.0, 26.0}, 
      points = {{-21.0, 9.0}, {-18.0, 9.0}, {-18.0, -20.0}, {23.0, -20.0}, {23.0, -10.0}}, 
      color = {127, 0, 127}));
  connect(chip_74LS00_1.Y_2, chip_74LS112_1.K_1)
    annotation (Line(origin = {-56.0, -31.0}, 
      points = {{13.0, 46.0}, {13.0, 22.0}, {-34.0, 22.0}, {-34.0, -54.0}, {-13.0, -54.0}, {-13.0, -47.0}}, 
      color = {127, 0, 127}));
  connect(chip_74LS112_1.PR_2, VCC.y)
    annotation (Line(origin = {-66.0, 8.0}, 
      points = {{35.0, -27.0}, {35.0, -14.0}, {-34.0, -14.0}, {-34.0, 27.0}}, 
      color = {127, 0, 127}));
  connect(chip_74LS112_1.CLR_2, VCC.y)
    annotation (Line(origin = {-82.0, 8.0}, 
      points = {{20.0, -27.0}, {20.0, -14.0}, {-18.0, -14.0}, {-18.0, 27.0}}, 
      color = {127, 0, 127}));
  connect(chip_74LS112_1.CLR_1, VCC.y)
    annotation (Line(origin = {-85.0, 8.0}, 
      points = {{16.0, -27.0}, {16.0, -14.0}, {-15.0, -14.0}, {-15.0, 27.0}}, 
      color = {127, 0, 127}));
  connect(chip_74LS112_1.PR_1, VCC.y)
    annotation (Line(origin = {-78.0, -21.0}, 
      points = {{24.0, -57.0}, {24.0, -66.0}, {-22.0, -66.0}, {-22.0, 56.0}}, 
      color = {127, 0, 127}));
  connect(chip_74LS112_2.CLR_1, VCC.y)
    annotation (Line(origin = {-34.0, 8.0}, 
      points = {{65.0, -27.0}, {65.0, -14.0}, {-66.0, -14.0}, {-66.0, 27.0}}, 
      color = {127, 0, 127}));
  connect(chip_74LS112_2.CLR_2, VCC.y)
    annotation (Line(origin = {-31.0, 8.0}, 
      points = {{69.0, -27.0}, {69.0, -14.0}, {-69.0, -14.0}, {-69.0, 27.0}}, 
      color = {127, 0, 127}));
  connect(chip_74LS112_2.PR_2, VCC.y)
    annotation (Line(origin = {-15.0, 8.0}, 
      points = {{84.0, -27.0}, {84.0, -14.0}, {-85.0, -14.0}, {-85.0, 27.0}}, 
      color = {127, 0, 127}));
  connect(chip_74LS112_2.PR_1, VCC.y)
    annotation (Line(origin = {-27.0, -21.0}, 
      points = {{73.0, -57.0}, {73.0, -66.0}, {-73.0, -66.0}, {-73.0, 56.0}}, 
      color = {127, 0, 127}));
  connect(chip_74LS112_2.Q_2, Q3.x)
    annotation (Line(origin = {59.0, 40.0}, 
      points = {{18.0, -59.0}, {18.0, 58.0}, {-19.0, 58.0}}, 
      color = {127, 0, 127}));
  connect(chip_74LS112_2.Q_1, Q2.x)
    annotation (Line(origin = {47.0, -1.0}, 
      points = {{6.0, -76.0}, {6.0, -98.0}, {44.0, -98.0}, {44.0, 75.0}, {-7.0, 75.0}}, 
      color = {127, 0, 127}));
  connect(chip_74LS112_1.Q_2, Q1.x)
    annotation (Line(origin = {9.0, 15.0}, 
      points = {{-32.0, -34.0}, {-32.0, -4.0}, {22.0, -4.0}, {22.0, 34.0}, {31.0, 34.0}}, 
      color = {127, 0, 127}));
  connect(chip_74LS112_1.Q_1, Q0.x)
    annotation (Line(origin = {-3.0, -26.0}, 
      points = {{-44.0, -51.0}, {-44.0, 24.0}, {40.0, 24.0}, {40.0, 51.0}, {43.0, 51.0}}, 
      color = {127, 0, 127}));
  connect(chip_74LS00_1.B_4, VCC.y)
    annotation (Line(origin = {-78.0, 56.0}, 
      points = {{21.0, 21.0}, {-22.0, 21.0}, {-22.0, -21.0}}, 
      color = {127, 0, 127}));
  connect(chip_74LS00_1.A_4, VCC.y)
    annotation (Line(origin = {-72.0, 56.0}, 
      points = {{27.0, 21.0}, {-28.0, 21.0}, {-28.0, -21.0}}, 
      color = {127, 0, 127}));
  connect(chip_74LS00_1.B_3, VCC.y)
    annotation (Line(origin = {-60.0, 48.0}, 
      points = {{40.0, 12.0}, {-40.0, 12.0}, {-40.0, -13.0}}, 
      color = {127, 0, 127}));
  connect(chip_74LS00_1.A_3, chip_74LS00_1.B_3)
    annotation (Line(origin = {-20.0, 55.0}, 
      points = {{0.0, -6.0}, {0.0, 5.0}}, 
      color = {127, 0, 127}));
end Exp4;