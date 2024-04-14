within ;
model Exp1
  import Modelica.Units.SI;
  import D = Modelica.Electrical.Digital;
  import L = Modelica.Electrical.Digital.Interfaces.Logic;
  LogicDesignSimulation.chip_74LS.chip_74LS00.chip_74LS00 chip_74LS00_1 annotation (Placement(transformation(origin = {-50.55072463768117, -3.7101449275362377}, 
    extent = {{-35.97101449275363, -35.97101449275363}, {35.97101449275363, 35.97101449275363}})));

  LogicDesignSimulation.chip_74LS.chip_74LS86.chip_74LS86 chip_74LS86_1 annotation (Placement(transformation(origin = {61.68115942028988, -1.8550724637681206}, 
    extent = {{-35.5072463768116, -35.507246376811594}, {35.507246376811594, 35.5072463768116}})));

  Modelica.Electrical.Digital.Sources.Pulse tableA annotation (Placement(transformation(origin = {-196.4965159190823, 92.34641914218355}, 
    extent = {{-15.323227168597043, -15.323227168597057}, {15.323227168597072, 15.32322716859705}})));

  Modelica.Electrical.Digital.Sources.Pulse tableB(period = 2) annotation (Placement(transformation(origin = {-195.57073728106542, 47.909044517373424}, 
    extent = {{-15.323227168597043, -15.323227168597057}, {15.323227168597072, 15.32322716859705}})));

  Modelica.Electrical.Digital.Sources.Pulse tableC(period = 4) annotation (Placement(transformation(origin = {-196.03362660007386, -0.23144465950421278}, 
    extent = {{-15.323227168597043, -15.323227168597057}, {15.323227168597072, 15.32322716859705}})));
  Modelica.Electrical.Digital.Interfaces.DigitalOutput S_i
    annotation (Placement(transformation(origin = {84.52167250603834, -90.4191433392215}, 
      extent = {{-10.0, -10.0}, {10.0, 10.0}})));
  Modelica.Electrical.Digital.Interfaces.DigitalOutput C_i_1
    annotation (Placement(transformation(origin = {6.675964511496225, -88.32707653523586}, 
      extent = {{-10.0, -10.0}, {10.0, 10.0}})));
  Modelica.Electrical.Digital.Sources.Set set
    annotation (Placement(transformation(origin = {77.46638497789277, 97.83717510170901}, 
      extent = {{-10.0, -10.0}, {10.0, 10.0}})));
equation 
  connect(tableA.y, chip_74LS86_1.A_1)
    annotation (Line(origin = {-74.0, 28.0}, 
      points = {{-107.0, 64.0}, {95.0, 64.0}, {95.0, -65.0}, {106.0, -65.0}}, 
      color = {127, 0, 127}));
  connect(tableB.y, chip_74LS86_1.B_1)
    annotation (Line(origin = {-69.0, 6.0}, 
      points = {{-111.0, 42.0}, {84.0, 42.0}, {84.0, -49.0}, {111.0, -49.0}, {111.0, -43.0}}, 
      color = {127, 0, 127}));
  connect(chip_74LS86_1.Y_1, chip_74LS86_1.A_2)
    annotation (Line(origin = {77.0, -1.0}, 
      points = {{-23.0, -36.0}, {-23.0, -48.0}, {-14.0, -48.0}, {-14.0, -37.0}}, 
      color = {127, 0, 127}));
  connect(tableC.y, chip_74LS86_1.B_2)
    annotation (Line(origin = {-54.0, -19.0}, 
      points = {{-127.0, 19.0}, {-85.0, 19.0}, {-85.0, -40.0}, {126.0, -40.0}, {126.0, -19.0}}, 
      color = {127, 0, 127}));
  connect(chip_74LS86_1.Y_2, S_i)
    annotation (Line(origin = {83.0, -58.0}, 
      points = {{0.0, 21.0}, {0.0, -32.0}, {2.0, -32.0}}, 
      color = {127, 0, 127}));
  connect(tableA.y, chip_74LS00_1.A_1)
    annotation (Line(origin = {-133.0, 51.0}, 
      points = {{-48.0, 41.0}, {-48.0, 38.0}, {31.0, 38.0}, {31.0, -42.0}, {47.0, -42.0}}, 
      color = {127, 0, 127}));
  connect(tableB.y, chip_74LS00_1.B_1)
    annotation (Line(origin = {-133.0, 22.0}, 
      points = {{-47.0, 26.0}, {-47.0, 21.0}, {26.0, 21.0}, {26.0, -26.0}, {47.0, -26.0}}, 
      color = {127, 0, 127}));
  connect(tableC.y, chip_74LS00_1.B_2)
    annotation (Line(origin = {-119.0, -20.0}, 
      points = {{-62.0, 20.0}, {-62.0, -45.0}, {62.0, -45.0}, {62.0, -20.0}}, 
      color = {127, 0, 127}));
  connect(chip_74LS86_1.Y_1, chip_74LS00_1.A_2)
    annotation (Line(origin = {-10.0, -38.0}, 
      points = {{64.0, 1.0}, {64.0, -35.0}, {-65.0, -35.0}, {-65.0, -2.0}}, 
      color = {127, 0, 127}));
  connect(chip_74LS00_1.Y_2, chip_74LS00_1.A_3)
    annotation (Line(origin = {-27.0, -21.0}, 
      points = {{-15.0, -20.0}, {-15.0, -35.0}, {37.0, -35.0}, {37.0, 21.0}, {13.0, 21.0}}, 
      color = {127, 0, 127}));
  connect(chip_74LS00_1.Y_1, chip_74LS00_1.B_3)
    annotation (Line(origin = {-51.0, 7.0}, 
      points = {{-35.0, -24.0}, {-44.0, -24.0}, {-44.0, 37.0}, {59.0, 37.0}, {59.0, 6.0}, {37.0, 6.0}}, 
      color = {127, 0, 127}));
  connect(chip_74LS00_1.Y_3, C_i_1)
    annotation (Line(origin = {-3.0, -51.0}, 
      points = {{-11.0, 37.0}, {10.0, 37.0}, {10.0, -37.0}}, 
      color = {127, 0, 127}));
  connect(chip_74LS00_1.B_4, set.y)
    annotation (Line(origin = {14.0, 66.0}, 
      points = {{-73.0, -32.0}, {-73.0, 32.0}, {73.0, 32.0}}, 
      color = {127, 0, 127}));
  connect(chip_74LS00_1.A_4, set.y)
    annotation (Line(origin = {22.0, 66.0}, 
      points = {{-66.0, -33.0}, {-66.0, 32.0}, {65.0, 32.0}}, 
      color = {127, 0, 127}));
  connect(chip_74LS86_1.B_4, set.y)
    annotation (Line(origin = {64.0, 66.0}, 
      points = {{-23.0, -32.0}, {-23.0, 32.0}, {23.0, 32.0}}, 
      color = {127, 0, 127}));
  connect(chip_74LS86_1.A_4, set.y)
    annotation (Line(origin = {69.0, 66.0}, 
      points = {{-18.0, -32.0}, {-18.0, 32.0}, {18.0, 32.0}}, 
      color = {127, 0, 127}));
  connect(chip_74LS86_1.B_3, set.y)
    annotation (Line(origin = {79.0, 66.0}, 
      points = {{-8.0, -32.0}, {-8.0, 32.0}, {8.0, 32.0}}, 
      color = {127, 0, 127}));
  connect(chip_74LS86_1.A_3, set.y)
    annotation (Line(origin = {84.0, 66.0}, 
      points = {{-4.0, -32.0}, {-4.0, 32.0}, {3.0, 32.0}}, 
      color = {127, 0, 127}));
end Exp1;