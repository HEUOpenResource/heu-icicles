within ;
model Exp5
  import Modelica.Units.SI;
  import D = Modelica.Electrical.Digital;
  import L = Modelica.Electrical.Digital.Interfaces.Logic;
  LogicDesignSimulation.chip_74LS.chip_74LS00.chip_74LS00 chip_74LS1
    annotation (Placement(transformation(origin = {-32.0, 15.0}, 
      extent = {{-10.0, -10.0}, {10.0, 10.0}})));
  LogicDesignSimulation.chip_74LS.chip_74LS86.chip_74LS86 chip_74LS87
    annotation (Placement(transformation(origin = {24.0, 17.0}, 
      extent = {{-10.0, -10.0}, {10.0, 10.0}})));
  LogicDesignSimulation.chip_74LS.chip_74LS74.chip_74LS74 chip_74LS75
    annotation (Placement(transformation(origin = {-34.0, -34.0}, 
      extent = {{-10.0, -10.0}, {10.0, 10.0}})));
  Modelica.Electrical.Digital.Sources.Pulse Pulse1 "Digital Pulse Source" 
    annotation (Placement(transformation(origin = {-94.0, -11.0}, 
      extent = {{-10.0, -10.0}, {10.0, 10.0}})));
  LogicDesignSimulation.chip_74LS.chip_74LS74.chip_74LS74 chip_74LS76
    annotation (Placement(transformation(origin = {23.0, -34.0}, 
      extent = {{-10.0, -10.0}, {10.0, 10.0}})));
  LogicDesignSimulation.chip_74LS.utils.OutNode Q0
    annotation (Placement(transformation(origin = {90.0, 47.0}, 
      extent = {{-10.0, -10.0}, {10.0, 10.0}})));
  LogicDesignSimulation.chip_74LS.utils.OutNode Q1
    annotation (Placement(transformation(origin = {90.0, 16.0}, 
      extent = {{-10.0, -10.0}, {10.0, 10.0}})));
  LogicDesignSimulation.chip_74LS.utils.OutNode Q2
    annotation (Placement(transformation(origin = {90.0, -15.0}, 
      extent = {{-10.0, -10.0}, {10.0, 10.0}})));
  LogicDesignSimulation.chip_74LS.utils.OutNode Q3
    annotation (Placement(transformation(origin = {90.0, -46.0}, 
      extent = {{-10.0, -10.0}, {10.0, 10.0}})));
  Modelica.Electrical.Digital.Sources.Set Ignore "Digital Set Source" 
    annotation (Placement(transformation(origin = {-95.0, 47.0}, 
      extent = {{-10.0, -10.0}, {10.0, 10.0}})));
equation 
  connect(Pulse1.y, chip_74LS75.CK_2)
    annotation (Line(origin = {0.0, 0.0}, 
      points = {{-84.0, -11.0}, {-33.0, -11.0}, {-33.0, -24.0}}));
  connect(Pulse1.y, chip_74LS76.CK_2)
    annotation (Line(origin = {0.0, 0.0}, 
      points = {{-84.0, -11.0}, {22.0, -11.0}, {22.0, -24.0}}));
  connect(Pulse1.y, chip_74LS75.CK_1)
    annotation (Line(origin = {0.0, 0.0}, 
      points = {{-84.0, -11.0}, {-69.0, -11.0}, {-69.0, -58.0}, {-36.0, -58.0}, {-36.0, -43.0}}));
  connect(Pulse1.y, chip_74LS76.CK_1)
    annotation (Line(origin = {0.0, 0.0}, 
      points = {{-84.0, -11.0}, {-69.0, -11.0}, {-69.0, -58.0}, {20.0, -58.0}, {20.0, -44.0}, {19.0, -44.0}, {19.0, -43.0}}));
  connect(chip_74LS1.Y_1, chip_74LS75.D_1)
    annotation (Line(origin = {0.0, 0.0}, 
      points = {{-41.0, 11.0}, {-57.0, 11.0}, {-57.0, -50.0}, {-40.0, -50.0}, {-40.0, -43.0}, {-39.0, -43.0}}));
  connect(chip_74LS75.Q_1, chip_74LS87.A_1)
    annotation (Line(origin = {0.0, 0.0}, 
      points = {{-31.0, -43.0}, {-32.0, -43.0}, {-32.0, -50.0}, {-1.0, -50.0}, {-1.0, 0.0}, {16.0, 0.0}, {16.0, 6.0}, {15.0, 6.0}}));
  connect(chip_74LS75.Q_2, chip_74LS87.B_1)
    annotation (Line(origin = {0.0, 0.0}, 
      points = {{-28.0, -24.0}, {-29.0, -24.0}, {-29.0, -15.0}, {19.0, -15.0}, {19.0, 6.0}, {18.0, 6.0}, {18.0, 7.0}}));
  connect(chip_74LS87.Y_1, chip_74LS75.D_2)
    annotation (Line(origin = {0.0, 0.0}, 
      points = {{21.0, 7.0}, {21.0, -8.0}, {-37.0, -8.0}, {-37.0, -24.0}}));
  connect(chip_74LS75.Q_2, chip_74LS87.A_2)
    annotation (Line(origin = {0.0, 0.0}, 
      points = {{-28.0, -24.0}, {-29.0, -24.0}, {-29.0, -15.0}, {24.0, -15.0}, {24.0, 6.0}}));
  connect(chip_74LS76.Q_1, chip_74LS87.B_2)
    annotation (Line(origin = {0.0, 0.0}, 
      points = {{25.0, -43.0}, {45.0, -43.0}, {45.0, -8.0}, {27.0, -8.0}, {27.0, 6.0}, {26.0, 6.0}}));
  connect(chip_74LS87.Y_2, chip_74LS76.D_1)
    annotation (Line(origin = {0.0, 0.0}, 
      points = {{29.0, 6.0}, {30.0, 6.0}, {30.0, -19.0}, {6.0, -19.0}, {6.0, -50.0}, {17.0, -50.0}, {17.0, -43.0}}));
  connect(chip_74LS1.Y_1, chip_74LS87.B_4)
    annotation (Line(origin = {0.0, 0.0}, 
      points = {{-41.0, 11.0}, {-57.0, 11.0}, {-57.0, 37.0}, {18.0, 37.0}, {18.0, 27.0}}));
  connect(chip_74LS76.QB_2, chip_74LS87.A_4)
    annotation (Line(origin = {0.0, 0.0}, 
      points = {{32.0, -24.0}, {42.0, -24.0}, {42.0, 37.0}, {21.0, 37.0}, {21.0, 27.0}}));
  connect(chip_74LS87.Y_4, chip_74LS76.D_2)
    annotation (Line(origin = {0.0, 0.0}, 
      points = {{24.0, 27.0}, {24.0, 41.0}, {36.0, 41.0}, {36.0, -17.0}, {20.0, -17.0}, {20.0, -24.0}, {19.0, -24.0}}));
  connect(chip_74LS76.Q_2, Q0.x)
    annotation (Line(origin = {0.0, 0.0}, 
      points = {{28.0, -24.0}, {55.0, -24.0}, {55.0, 47.0}, {80.0, 47.0}, {80.0, 46.0}}));
  connect(chip_74LS76.Q_1, Q1.x)
    annotation (Line(origin = {0.0, 0.0}, 
      points = {{25.0, -43.0}, {59.0, -43.0}, {59.0, 16.0}, {80.0, 16.0}, {80.0, 15.0}}));
  connect(chip_74LS75.Q_2, Q2.x)
    annotation (Line(origin = {0.0, 0.0}, 
      points = {{-28.0, -24.0}, {-29.0, -24.0}, {-29.0, -15.0}, {80.0, -15.0}}));
  connect(chip_74LS75.Q_1, Q3.x)
    annotation (Line(origin = {0.0, 0.0}, 
      points = {{-31.0, -43.0}, {-32.0, -43.0}, {-32.0, -46.0}, {80.0, -46.0}}));
  connect(Ignore.y, chip_74LS1.Vcc)
    annotation (Line(origin = {0.0, 0.0}, 
      points = {{-85.0, 47.0}, {-39.0, 47.0}, {-39.0, 25.0}}));
  connect(Ignore.y, chip_74LS1.B_4)
    annotation (Line(origin = {0.0, 0.0}, 
      points = {{-85.0, 47.0}, {-34.0, 47.0}, {-34.0, 25.0}}));
  connect(Ignore.y, chip_74LS1.A_4)
    annotation (Line(origin = {0.0, 0.0}, 
      points = {{-85.0, 47.0}, {-30.0, 47.0}, {-30.0, 25.0}}));
  connect(Ignore.y, chip_74LS1.B_3)
    annotation (Line(origin = {0.0, 0.0}, 
      points = {{-85.0, 47.0}, {-18.0, 47.0}, {-18.0, 20.0}, {-21.0, 20.0}, {-21.0, 19.0}}));
  connect(Ignore.y, chip_74LS1.A_3)
    annotation (Line(origin = {0.0, 0.0}, 
      points = {{-85.0, 47.0}, {-18.0, 47.0}, {-18.0, 16.0}, {-21.0, 16.0}}));
  connect(chip_74LS75.Q_2, chip_74LS1.B_1)
    annotation (Line(origin = {0.0, 0.0}, 
      points = {{-28.0, -24.0}, {-27.0, -24.0}, {-27.0, 15.0}, {-42.0, 15.0}, {-42.0, 14.0}, {-41.0, 14.0}}));
  connect(chip_74LS76.Q_1, chip_74LS1.A_1)
    annotation (Line(origin = {0.0, 0.0}, 
      points = {{25.0, -43.0}, {25.0, -56.0}, {-64.0, -56.0}, {-64.0, 18.0}, {-41.0, 18.0}}));
  connect(Ignore.y, chip_74LS1.A_2)
    annotation (Line(origin = {0.0, 0.0}, 
      points = {{-85.0, 47.0}, {-72.0, 47.0}, {-72.0, 1.0}, {-39.0, 1.0}, {-39.0, 5.0}, {-38.0, 5.0}}));
  connect(Ignore.y, chip_74LS1.B_2)
    annotation (Line(origin = {0.0, 0.0}, 
      points = {{-85.0, 47.0}, {-72.0, 47.0}, {-72.0, 1.0}, {-34.0, 1.0}, {-34.0, 5.0}, {-33.0, 5.0}, {-33.0, 4.0}}));
  connect(Ignore.y, chip_74LS1.GND)
    annotation (Line(origin = {0.0, 0.0}, 
      points = {{-85.0, 47.0}, {-72.0, 47.0}, {-72.0, 1.0}, {-26.0, 1.0}, {-26.0, 5.0}, {-25.0, 5.0}, {-25.0, 4.0}}));
  connect(Ignore.y, chip_74LS87.B_3)
    annotation (Line(origin = {0.0, 0.0}, 
      points = {{-85.0, 47.0}, {26.0, 47.0}, {26.0, 27.0}}));
  connect(Ignore.y, chip_74LS87.A_3)
    annotation (Line(origin = {0.0, 0.0}, 
      points = {{-85.0, 47.0}, {29.0, 47.0}, {29.0, 27.0}}));
  connect(Ignore.y, chip_74LS75.Vcc)
    annotation (Line(origin = {0.0, 0.0}, 
      points = {{-85.0, 47.0}, {-72.0, 47.0}, {-72.0, -16.0}, {-43.0, -16.0}, {-43.0, -24.0}, {-42.0, -24.0}}));
  connect(Ignore.y, chip_74LS75.CLR_2)
    annotation (Line(origin = {0.0, 0.0}, 
      points = {{-85.0, 47.0}, {-72.0, 47.0}, {-72.0, -16.0}, {-40.0, -16.0}, {-40.0, -24.0}}));
  connect(Ignore.y, chip_74LS75.PR_2)
    annotation (Line(origin = {0.0, 0.0}, 
      points = {{-85.0, 47.0}, {-72.0, 47.0}, {-72.0, -16.0}, {-31.0, -16.0}, {-31.0, -24.0}}));
  connect(Ignore.y, chip_74LS75.CLR_1)
    annotation (Line(origin = {0.0, 0.0}, 
      points = {{-85.0, 47.0}, {-72.0, 47.0}, {-72.0, -53.0}, {-43.0, -53.0}, {-43.0, -43.0}, {-42.0, -43.0}}));
  connect(Ignore.y, chip_74LS75.PR_1)
    annotation (Line(origin = {0.0, 0.0}, 
      points = {{-85.0, 47.0}, {-72.0, 47.0}, {-72.0, -53.0}, {-34.0, -53.0}, {-34.0, -43.0}}));
  connect(Ignore.y, chip_74LS75.GND)
    annotation (Line(origin = {0.0, 0.0}, 
      points = {{-85.0, 47.0}, {-72.0, 47.0}, {-72.0, -53.0}, {-25.0, -53.0}, {-25.0, -43.0}, {-24.0, -43.0}}));
  connect(Ignore.y, chip_74LS76.Vcc)
    annotation (Line(origin = {0.0, 0.0}, 
      points = {{-85.0, 47.0}, {-6.0, 47.0}, {-6.0, -21.0}, {14.0, -21.0}, {14.0, -24.0}}));
  connect(Ignore.y, chip_74LS76.CLR_2)
    annotation (Line(origin = {0.0, 0.0}, 
      points = {{-85.0, 47.0}, {-6.0, 47.0}, {-6.0, -21.0}, {17.0, -21.0}, {17.0, -24.0}, {16.0, -24.0}}));
  connect(Ignore.y, chip_74LS76.PR_2)
    annotation (Line(origin = {0.0, 0.0}, 
      points = {{-85.0, 47.0}, {-6.0, 47.0}, {-6.0, -21.0}, {26.0, -21.0}, {26.0, -24.0}, {25.0, -24.0}}));
  connect(Ignore.y, chip_74LS76.CLR_1)
    annotation (Line(origin = {0.0, 0.0}, 
      points = {{-85.0, 47.0}, {-6.0, 47.0}, {-6.0, -53.0}, {14.0, -53.0}, {14.0, -43.0}}));
  connect(Ignore.y, chip_74LS76.PR_1)
    annotation (Line(origin = {0.0, 0.0}, 
      points = {{-85.0, 47.0}, {-6.0, 47.0}, {-6.0, -53.0}, {23.0, -53.0}, {23.0, -43.0}, {22.0, -43.0}}));
  connect(Ignore.y, chip_74LS76.GND)
    annotation (Line(origin = {0.0, 0.0}, 
      points = {{-85.0, 47.0}, {48.0, 47.0}, {48.0, -44.0}, {32.0, -44.0}, {32.0, -43.0}}));
end Exp5;