  function targMap = targDataMap(),

  ;%***********************
  ;% Create Parameter Map *
  ;%***********************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 12;
    sectIdxOffset = 0;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc paramMap
    ;%
    paramMap.nSections           = nTotSects;
    paramMap.sectIdxOffset       = sectIdxOffset;
      paramMap.sections(nTotSects) = dumSection; %prealloc
    paramMap.nTotData            = -1;
    
    ;%
    ;% Auto data (acvh_controller_mark1_P)
    ;%
      section.nData     = 38;
      section.data(38)  = dumData; %prealloc
      
	  ;% acvh_controller_mark1_P.DiscretePIDController1_D
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% acvh_controller_mark1_P.Kfy_D
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% acvh_controller_mark1_P.tau_roll1_D
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% acvh_controller_mark1_P.Kfx_D
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
	  ;% acvh_controller_mark1_P.tau_pitch1_D
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 4;
	
	  ;% acvh_controller_mark1_P.DiscretePIDController1_I
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 5;
	
	  ;% acvh_controller_mark1_P.tau_pitch1_I
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 6;
	
	  ;% acvh_controller_mark1_P.Kfx_I
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 7;
	
	  ;% acvh_controller_mark1_P.tau_roll1_I
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 8;
	
	  ;% acvh_controller_mark1_P.Kfy_I
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 9;
	
	  ;% acvh_controller_mark1_P.DiscretePIDController1_InitialC
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 10;
	
	  ;% acvh_controller_mark1_P.Kfy_InitialConditionForFilter
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 11;
	
	  ;% acvh_controller_mark1_P.tau_roll1_InitialConditionForFi
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 12;
	
	  ;% acvh_controller_mark1_P.Kfx_InitialConditionForFilter
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 13;
	
	  ;% acvh_controller_mark1_P.tau_pitch1_InitialConditionForF
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 14;
	
	  ;% acvh_controller_mark1_P.DiscretePIDController1_Initia_j
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 15;
	
	  ;% acvh_controller_mark1_P.Kfy_InitialConditionForIntegrat
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 16;
	
	  ;% acvh_controller_mark1_P.tau_roll1_InitialConditionForIn
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 17;
	
	  ;% acvh_controller_mark1_P.Kfx_InitialConditionForIntegrat
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 18;
	
	  ;% acvh_controller_mark1_P.tau_pitch1_InitialConditionForI
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 19;
	
	  ;% acvh_controller_mark1_P.Kfy_LowerSaturationLimit
	  section.data(21).logicalSrcIdx = 20;
	  section.data(21).dtTransOffset = 20;
	
	  ;% acvh_controller_mark1_P.tau_roll1_LowerSaturationLimit
	  section.data(22).logicalSrcIdx = 21;
	  section.data(22).dtTransOffset = 21;
	
	  ;% acvh_controller_mark1_P.Kfx_LowerSaturationLimit
	  section.data(23).logicalSrcIdx = 22;
	  section.data(23).dtTransOffset = 22;
	
	  ;% acvh_controller_mark1_P.tau_pitch1_LowerSaturationLimit
	  section.data(24).logicalSrcIdx = 23;
	  section.data(24).dtTransOffset = 23;
	
	  ;% acvh_controller_mark1_P.DiscretePIDController1_N
	  section.data(25).logicalSrcIdx = 24;
	  section.data(25).dtTransOffset = 24;
	
	  ;% acvh_controller_mark1_P.Kfy_N
	  section.data(26).logicalSrcIdx = 25;
	  section.data(26).dtTransOffset = 25;
	
	  ;% acvh_controller_mark1_P.tau_roll1_N
	  section.data(27).logicalSrcIdx = 26;
	  section.data(27).dtTransOffset = 26;
	
	  ;% acvh_controller_mark1_P.Kfx_N
	  section.data(28).logicalSrcIdx = 27;
	  section.data(28).dtTransOffset = 27;
	
	  ;% acvh_controller_mark1_P.tau_pitch1_N
	  section.data(29).logicalSrcIdx = 28;
	  section.data(29).dtTransOffset = 28;
	
	  ;% acvh_controller_mark1_P.DiscretePIDController1_P
	  section.data(30).logicalSrcIdx = 29;
	  section.data(30).dtTransOffset = 29;
	
	  ;% acvh_controller_mark1_P.Kfy_P
	  section.data(31).logicalSrcIdx = 30;
	  section.data(31).dtTransOffset = 30;
	
	  ;% acvh_controller_mark1_P.tau_roll1_P
	  section.data(32).logicalSrcIdx = 31;
	  section.data(32).dtTransOffset = 31;
	
	  ;% acvh_controller_mark1_P.Kfx_P
	  section.data(33).logicalSrcIdx = 32;
	  section.data(33).dtTransOffset = 32;
	
	  ;% acvh_controller_mark1_P.tau_pitch1_P
	  section.data(34).logicalSrcIdx = 33;
	  section.data(34).dtTransOffset = 33;
	
	  ;% acvh_controller_mark1_P.Kfy_UpperSaturationLimit
	  section.data(35).logicalSrcIdx = 34;
	  section.data(35).dtTransOffset = 34;
	
	  ;% acvh_controller_mark1_P.tau_roll1_UpperSaturationLimit
	  section.data(36).logicalSrcIdx = 35;
	  section.data(36).dtTransOffset = 35;
	
	  ;% acvh_controller_mark1_P.Kfx_UpperSaturationLimit
	  section.data(37).logicalSrcIdx = 36;
	  section.data(37).dtTransOffset = 36;
	
	  ;% acvh_controller_mark1_P.tau_pitch1_UpperSaturationLimit
	  section.data(38).logicalSrcIdx = 37;
	  section.data(38).dtTransOffset = 37;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(1) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% acvh_controller_mark1_P.Out1_Y0
	  section.data(1).logicalSrcIdx = 38;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(2) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% acvh_controller_mark1_P.Constant_Value
	  section.data(1).logicalSrcIdx = 39;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(3) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% acvh_controller_mark1_P.Out1_Y0_f
	  section.data(1).logicalSrcIdx = 40;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(4) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% acvh_controller_mark1_P.Constant_Value_n
	  section.data(1).logicalSrcIdx = 41;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(5) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% acvh_controller_mark1_P.Out1_Y0_l
	  section.data(1).logicalSrcIdx = 42;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(6) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% acvh_controller_mark1_P.Constant_Value_j
	  section.data(1).logicalSrcIdx = 43;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(7) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% acvh_controller_mark1_P.Out1_Y0_n
	  section.data(1).logicalSrcIdx = 44;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(8) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% acvh_controller_mark1_P.Constant_Value_l
	  section.data(1).logicalSrcIdx = 45;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(9) = section;
      clear section
      
      section.nData     = 34;
      section.data(34)  = dumData; %prealloc
      
	  ;% acvh_controller_mark1_P.Constant_Value_p
	  section.data(1).logicalSrcIdx = 46;
	  section.data(1).dtTransOffset = 0;
	
	  ;% acvh_controller_mark1_P.Constant_Value_o
	  section.data(2).logicalSrcIdx = 47;
	  section.data(2).dtTransOffset = 1;
	
	  ;% acvh_controller_mark1_P.Constant_Value_na
	  section.data(3).logicalSrcIdx = 48;
	  section.data(3).dtTransOffset = 2;
	
	  ;% acvh_controller_mark1_P.Constant1_Value
	  section.data(4).logicalSrcIdx = 49;
	  section.data(4).dtTransOffset = 3;
	
	  ;% acvh_controller_mark1_P.Constant1_Value_o
	  section.data(5).logicalSrcIdx = 50;
	  section.data(5).dtTransOffset = 4;
	
	  ;% acvh_controller_mark1_P.Mixermatrix_Value
	  section.data(6).logicalSrcIdx = 51;
	  section.data(6).dtTransOffset = 5;
	
	  ;% acvh_controller_mark1_P.Constant_Value_n2
	  section.data(7).logicalSrcIdx = 52;
	  section.data(7).dtTransOffset = 21;
	
	  ;% acvh_controller_mark1_P.Integrator_gainval
	  section.data(8).logicalSrcIdx = 53;
	  section.data(8).dtTransOffset = 22;
	
	  ;% acvh_controller_mark1_P.Tsamp_WtEt
	  section.data(9).logicalSrcIdx = 54;
	  section.data(9).dtTransOffset = 23;
	
	  ;% acvh_controller_mark1_P.FilterDifferentiatorTF_NumCoef
	  section.data(10).logicalSrcIdx = 55;
	  section.data(10).dtTransOffset = 24;
	
	  ;% acvh_controller_mark1_P.Constant1_Value_i
	  section.data(11).logicalSrcIdx = 56;
	  section.data(11).dtTransOffset = 26;
	
	  ;% acvh_controller_mark1_P.Saturation2_UpperSat
	  section.data(12).logicalSrcIdx = 57;
	  section.data(12).dtTransOffset = 27;
	
	  ;% acvh_controller_mark1_P.Saturation2_LowerSat
	  section.data(13).logicalSrcIdx = 58;
	  section.data(13).dtTransOffset = 28;
	
	  ;% acvh_controller_mark1_P.Saturation3_UpperSat
	  section.data(14).logicalSrcIdx = 59;
	  section.data(14).dtTransOffset = 29;
	
	  ;% acvh_controller_mark1_P.Saturation3_LowerSat
	  section.data(15).logicalSrcIdx = 60;
	  section.data(15).dtTransOffset = 30;
	
	  ;% acvh_controller_mark1_P.Gain_Gain
	  section.data(16).logicalSrcIdx = 61;
	  section.data(16).dtTransOffset = 31;
	
	  ;% acvh_controller_mark1_P.Integrator_gainval_i
	  section.data(17).logicalSrcIdx = 62;
	  section.data(17).dtTransOffset = 32;
	
	  ;% acvh_controller_mark1_P.Filter_gainval
	  section.data(18).logicalSrcIdx = 63;
	  section.data(18).dtTransOffset = 33;
	
	  ;% acvh_controller_mark1_P.Integrator_gainval_n
	  section.data(19).logicalSrcIdx = 64;
	  section.data(19).dtTransOffset = 34;
	
	  ;% acvh_controller_mark1_P.Filter_gainval_p
	  section.data(20).logicalSrcIdx = 65;
	  section.data(20).dtTransOffset = 35;
	
	  ;% acvh_controller_mark1_P.RateLimiter4_RisingLim
	  section.data(21).logicalSrcIdx = 66;
	  section.data(21).dtTransOffset = 36;
	
	  ;% acvh_controller_mark1_P.RateLimiter4_FallingLim
	  section.data(22).logicalSrcIdx = 67;
	  section.data(22).dtTransOffset = 37;
	
	  ;% acvh_controller_mark1_P.RateLimiter4_IC
	  section.data(23).logicalSrcIdx = 68;
	  section.data(23).dtTransOffset = 38;
	
	  ;% acvh_controller_mark1_P.Integrator_gainval_c
	  section.data(24).logicalSrcIdx = 69;
	  section.data(24).dtTransOffset = 39;
	
	  ;% acvh_controller_mark1_P.Filter_gainval_f
	  section.data(25).logicalSrcIdx = 70;
	  section.data(25).dtTransOffset = 40;
	
	  ;% acvh_controller_mark1_P.u_Gain
	  section.data(26).logicalSrcIdx = 71;
	  section.data(26).dtTransOffset = 41;
	
	  ;% acvh_controller_mark1_P.Integrator_gainval_p
	  section.data(27).logicalSrcIdx = 72;
	  section.data(27).dtTransOffset = 42;
	
	  ;% acvh_controller_mark1_P.Filter_gainval_n
	  section.data(28).logicalSrcIdx = 73;
	  section.data(28).dtTransOffset = 43;
	
	  ;% acvh_controller_mark1_P.RateLimiter3_RisingLim
	  section.data(29).logicalSrcIdx = 74;
	  section.data(29).dtTransOffset = 44;
	
	  ;% acvh_controller_mark1_P.RateLimiter3_FallingLim
	  section.data(30).logicalSrcIdx = 75;
	  section.data(30).dtTransOffset = 45;
	
	  ;% acvh_controller_mark1_P.RateLimiter3_IC
	  section.data(31).logicalSrcIdx = 76;
	  section.data(31).dtTransOffset = 46;
	
	  ;% acvh_controller_mark1_P.Gain1_Gain
	  section.data(32).logicalSrcIdx = 77;
	  section.data(32).dtTransOffset = 47;
	
	  ;% acvh_controller_mark1_P.ZeroGain_Gain
	  section.data(33).logicalSrcIdx = 78;
	  section.data(33).dtTransOffset = 48;
	
	  ;% acvh_controller_mark1_P.ZeroGain_Gain_b
	  section.data(34).logicalSrcIdx = 79;
	  section.data(34).dtTransOffset = 49;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(10) = section;
      clear section
      
      section.nData     = 9;
      section.data(9)  = dumData; %prealloc
      
	  ;% acvh_controller_mark1_P.Deadband3_Start
	  section.data(1).logicalSrcIdx = 80;
	  section.data(1).dtTransOffset = 0;
	
	  ;% acvh_controller_mark1_P.Deadband3_End
	  section.data(2).logicalSrcIdx = 81;
	  section.data(2).dtTransOffset = 1;
	
	  ;% acvh_controller_mark1_P.Gain_Gain_o
	  section.data(3).logicalSrcIdx = 82;
	  section.data(3).dtTransOffset = 2;
	
	  ;% acvh_controller_mark1_P.Saturation4_UpperSat
	  section.data(4).logicalSrcIdx = 83;
	  section.data(4).dtTransOffset = 3;
	
	  ;% acvh_controller_mark1_P.Saturation4_LowerSat
	  section.data(5).logicalSrcIdx = 84;
	  section.data(5).dtTransOffset = 4;
	
	  ;% acvh_controller_mark1_P.Deadband_Start
	  section.data(6).logicalSrcIdx = 85;
	  section.data(6).dtTransOffset = 5;
	
	  ;% acvh_controller_mark1_P.Deadband_End
	  section.data(7).logicalSrcIdx = 86;
	  section.data(7).dtTransOffset = 6;
	
	  ;% acvh_controller_mark1_P.Deadband1_Start
	  section.data(8).logicalSrcIdx = 87;
	  section.data(8).dtTransOffset = 7;
	
	  ;% acvh_controller_mark1_P.Deadband1_End
	  section.data(9).logicalSrcIdx = 88;
	  section.data(9).dtTransOffset = 8;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(11) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% acvh_controller_mark1_P.Reset_Value
	  section.data(1).logicalSrcIdx = 89;
	  section.data(1).dtTransOffset = 0;
	
	  ;% acvh_controller_mark1_P.Constant_Value_a
	  section.data(2).logicalSrcIdx = 90;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(12) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (parameter)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    paramMap.nTotData = nTotData;
    


  ;%**************************
  ;% Create Block Output Map *
  ;%**************************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 10;
    sectIdxOffset = 0;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc sigMap
    ;%
    sigMap.nSections           = nTotSects;
    sigMap.sectIdxOffset       = sectIdxOffset;
      sigMap.sections(nTotSects) = dumSection; %prealloc
    sigMap.nTotData            = -1;
    
    ;%
    ;% Auto data (acvh_controller_mark1_B)
    ;%
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% acvh_controller_mark1_B.In1
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(1) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% acvh_controller_mark1_B.In1_f
	  section.data(1).logicalSrcIdx = 1;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(2) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% acvh_controller_mark1_B.In1_p
	  section.data(1).logicalSrcIdx = 2;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(3) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% acvh_controller_mark1_B.In1_a
	  section.data(1).logicalSrcIdx = 3;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(4) = section;
      clear section
      
      section.nData     = 11;
      section.data(11)  = dumData; %prealloc
      
	  ;% acvh_controller_mark1_B.DataTypeConversion4
	  section.data(1).logicalSrcIdx = 4;
	  section.data(1).dtTransOffset = 0;
	
	  ;% acvh_controller_mark1_B.Sum
	  section.data(2).logicalSrcIdx = 7;
	  section.data(2).dtTransOffset = 1;
	
	  ;% acvh_controller_mark1_B.des_vx
	  section.data(3).logicalSrcIdx = 8;
	  section.data(3).dtTransOffset = 2;
	
	  ;% acvh_controller_mark1_B.Sum1
	  section.data(4).logicalSrcIdx = 9;
	  section.data(4).dtTransOffset = 3;
	
	  ;% acvh_controller_mark1_B.des_vy
	  section.data(5).logicalSrcIdx = 10;
	  section.data(5).dtTransOffset = 4;
	
	  ;% acvh_controller_mark1_B.VectorConcatenate
	  section.data(6).logicalSrcIdx = 11;
	  section.data(6).dtTransOffset = 5;
	
	  ;% acvh_controller_mark1_B.MatrixMultiply
	  section.data(7).logicalSrcIdx = 12;
	  section.data(7).dtTransOffset = 8;
	
	  ;% acvh_controller_mark1_B.Saturation
	  section.data(8).logicalSrcIdx = 13;
	  section.data(8).dtTransOffset = 10;
	
	  ;% acvh_controller_mark1_B.u
	  section.data(9).logicalSrcIdx = 14;
	  section.data(9).dtTransOffset = 11;
	
	  ;% acvh_controller_mark1_B.tau_roll_k
	  section.data(10).logicalSrcIdx = 15;
	  section.data(10).dtTransOffset = 12;
	
	  ;% acvh_controller_mark1_B.tau_pitch_k
	  section.data(11).logicalSrcIdx = 16;
	  section.data(11).dtTransOffset = 13;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(5) = section;
      clear section
      
      section.nData     = 7;
      section.data(7)  = dumData; %prealloc
      
	  ;% acvh_controller_mark1_B.z
	  section.data(1).logicalSrcIdx = 17;
	  section.data(1).dtTransOffset = 0;
	
	  ;% acvh_controller_mark1_B.Gain
	  section.data(2).logicalSrcIdx = 18;
	  section.data(2).dtTransOffset = 1;
	
	  ;% acvh_controller_mark1_B.des_z
	  section.data(3).logicalSrcIdx = 19;
	  section.data(3).dtTransOffset = 2;
	
	  ;% acvh_controller_mark1_B.x
	  section.data(4).logicalSrcIdx = 20;
	  section.data(4).dtTransOffset = 3;
	
	  ;% acvh_controller_mark1_B.y
	  section.data(5).logicalSrcIdx = 21;
	  section.data(5).dtTransOffset = 4;
	
	  ;% acvh_controller_mark1_B.r
	  section.data(6).logicalSrcIdx = 22;
	  section.data(6).dtTransOffset = 5;
	
	  ;% acvh_controller_mark1_B.pressure
	  section.data(7).logicalSrcIdx = 23;
	  section.data(7).dtTransOffset = 6;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(6) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% acvh_controller_mark1_B.NOT
	  section.data(1).logicalSrcIdx = 24;
	  section.data(1).dtTransOffset = 0;
	
	  ;% acvh_controller_mark1_B.NOT_a
	  section.data(2).logicalSrcIdx = 25;
	  section.data(2).dtTransOffset = 1;
	
	  ;% acvh_controller_mark1_B.NOT_m
	  section.data(3).logicalSrcIdx = 26;
	  section.data(3).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(7) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (signal)
      ;%
	      
	    ;% tau_thrust
	    section.nData = 1;
	    section.data(1).logicalSrcIdx = 100;
	    section.data(1).dtTransOffset = 0;
	  
	    nTotData = nTotData + section.nData;
	    sigMap.sections(8) = section;
	    clear section
	  
	      
	    ;% tau_roll
	    section.nData = 1;
	    section.data(1).logicalSrcIdx = 101;
	    section.data(1).dtTransOffset = 0;
	  
	    nTotData = nTotData + section.nData;
	    sigMap.sections(9) = section;
	    clear section
	  
	      
	    ;% tau_pitch
	    section.nData = 1;
	    section.data(1).logicalSrcIdx = 102;
	    section.data(1).dtTransOffset = 0;
	  
	    nTotData = nTotData + section.nData;
	    sigMap.sections(10) = section;
	    clear section
	  
    

    ;%
    ;% Add final counts to struct.
    ;%
    sigMap.nTotData = nTotData;
    


  ;%*******************
  ;% Create DWork Map *
  ;%*******************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 6;
    sectIdxOffset = 10;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc dworkMap
    ;%
    dworkMap.nSections           = nTotSects;
    dworkMap.sectIdxOffset       = sectIdxOffset;
      dworkMap.sections(nTotSects) = dumSection; %prealloc
    dworkMap.nTotData            = -1;
    
    ;%
    ;% Auto data (acvh_controller_mark1_DW)
    ;%
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% acvh_controller_mark1_DW.obj
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% acvh_controller_mark1_DW.obj_j
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% acvh_controller_mark1_DW.obj_ji
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% acvh_controller_mark1_DW.obj_l
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(1) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% acvh_controller_mark1_DW.obj_e
	  section.data(1).logicalSrcIdx = 4;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(2) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% acvh_controller_mark1_DW.obj_en
	  section.data(1).logicalSrcIdx = 5;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(3) = section;
      clear section
      
      section.nData     = 12;
      section.data(12)  = dumData; %prealloc
      
	  ;% acvh_controller_mark1_DW.Integrator_DSTATE
	  section.data(1).logicalSrcIdx = 6;
	  section.data(1).dtTransOffset = 0;
	
	  ;% acvh_controller_mark1_DW.FilterDifferentiatorTF_states
	  section.data(2).logicalSrcIdx = 7;
	  section.data(2).dtTransOffset = 1;
	
	  ;% acvh_controller_mark1_DW.Integrator_DSTATE_m
	  section.data(3).logicalSrcIdx = 8;
	  section.data(3).dtTransOffset = 2;
	
	  ;% acvh_controller_mark1_DW.Filter_DSTATE
	  section.data(4).logicalSrcIdx = 9;
	  section.data(4).dtTransOffset = 3;
	
	  ;% acvh_controller_mark1_DW.Integrator_DSTATE_j
	  section.data(5).logicalSrcIdx = 10;
	  section.data(5).dtTransOffset = 4;
	
	  ;% acvh_controller_mark1_DW.Filter_DSTATE_d
	  section.data(6).logicalSrcIdx = 11;
	  section.data(6).dtTransOffset = 5;
	
	  ;% acvh_controller_mark1_DW.Integrator_DSTATE_e
	  section.data(7).logicalSrcIdx = 12;
	  section.data(7).dtTransOffset = 6;
	
	  ;% acvh_controller_mark1_DW.Filter_DSTATE_d4
	  section.data(8).logicalSrcIdx = 13;
	  section.data(8).dtTransOffset = 7;
	
	  ;% acvh_controller_mark1_DW.Integrator_DSTATE_ji
	  section.data(9).logicalSrcIdx = 14;
	  section.data(9).dtTransOffset = 8;
	
	  ;% acvh_controller_mark1_DW.Filter_DSTATE_b
	  section.data(10).logicalSrcIdx = 15;
	  section.data(10).dtTransOffset = 9;
	
	  ;% acvh_controller_mark1_DW.PrevY
	  section.data(11).logicalSrcIdx = 17;
	  section.data(11).dtTransOffset = 10;
	
	  ;% acvh_controller_mark1_DW.PrevY_d
	  section.data(12).logicalSrcIdx = 18;
	  section.data(12).dtTransOffset = 11;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(4) = section;
      clear section
      
      section.nData     = 6;
      section.data(6)  = dumData; %prealloc
      
	  ;% acvh_controller_mark1_DW.Scope1_PWORK.LoggedData
	  section.data(1).logicalSrcIdx = 19;
	  section.data(1).dtTransOffset = 0;
	
	  ;% acvh_controller_mark1_DW.Scope5_PWORK.LoggedData
	  section.data(2).logicalSrcIdx = 20;
	  section.data(2).dtTransOffset = 2;
	
	  ;% acvh_controller_mark1_DW.Scope3_PWORK.LoggedData
	  section.data(3).logicalSrcIdx = 21;
	  section.data(3).dtTransOffset = 4;
	
	  ;% acvh_controller_mark1_DW.Scope2_PWORK.LoggedData
	  section.data(4).logicalSrcIdx = 22;
	  section.data(4).dtTransOffset = 6;
	
	  ;% acvh_controller_mark1_DW.Scope6_PWORK.LoggedData
	  section.data(5).logicalSrcIdx = 23;
	  section.data(5).dtTransOffset = 8;
	
	  ;% acvh_controller_mark1_DW.Scope4_PWORK.LoggedData
	  section.data(6).logicalSrcIdx = 24;
	  section.data(6).dtTransOffset = 10;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(5) = section;
      clear section
      
      section.nData     = 7;
      section.data(7)  = dumData; %prealloc
      
	  ;% acvh_controller_mark1_DW.EnabledSubsystem_SubsysRanBC
	  section.data(1).logicalSrcIdx = 25;
	  section.data(1).dtTransOffset = 0;
	
	  ;% acvh_controller_mark1_DW.IfActionSubsystem2_SubsysRanBC
	  section.data(2).logicalSrcIdx = 26;
	  section.data(2).dtTransOffset = 1;
	
	  ;% acvh_controller_mark1_DW.IfActionSubsystem1_SubsysRanBC
	  section.data(3).logicalSrcIdx = 27;
	  section.data(3).dtTransOffset = 2;
	
	  ;% acvh_controller_mark1_DW.IfActionSubsystem_SubsysRanBC
	  section.data(4).logicalSrcIdx = 28;
	  section.data(4).dtTransOffset = 3;
	
	  ;% acvh_controller_mark1_DW.EnabledSubsystem_SubsysRanBC_g
	  section.data(5).logicalSrcIdx = 29;
	  section.data(5).dtTransOffset = 4;
	
	  ;% acvh_controller_mark1_DW.EnabledSubsystem_SubsysRanBC_o
	  section.data(6).logicalSrcIdx = 30;
	  section.data(6).dtTransOffset = 5;
	
	  ;% acvh_controller_mark1_DW.EnabledSubsystem_SubsysRanBC_c
	  section.data(7).logicalSrcIdx = 31;
	  section.data(7).dtTransOffset = 6;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(6) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (dwork)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    dworkMap.nTotData = nTotData;
    


  ;%
  ;% Add individual maps to base struct.
  ;%

  targMap.paramMap  = paramMap;    
  targMap.signalMap = sigMap;
  targMap.dworkMap  = dworkMap;
  
  ;%
  ;% Add checksums to base struct.
  ;%


  targMap.checksum0 = 3879447087;
  targMap.checksum1 = 505237397;
  targMap.checksum2 = 2269478722;
  targMap.checksum3 = 2640668163;

