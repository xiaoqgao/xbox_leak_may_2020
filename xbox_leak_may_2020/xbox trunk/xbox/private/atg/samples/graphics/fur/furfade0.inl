// Xbox Shader Assembler 1.00.4355.1
D3DPIXELSHADERDEF psd;
ZeroMemory(&psd, sizeof(psd));
psd.PSCombinerCount=PS_COMBINERCOUNT(
    2,
    PS_COMBINERCOUNT_MUX_MSB | PS_COMBINERCOUNT_UNIQUE_C0 | PS_COMBINERCOUNT_UNIQUE_C1);
psd.PSTextureModes=PS_TEXTUREMODES(
    PS_TEXTUREMODES_PROJECT2D,
    PS_TEXTUREMODES_PROJECT2D,
    PS_TEXTUREMODES_NONE,
    PS_TEXTUREMODES_NONE);
psd.PSInputTexture=PS_INPUTTEXTURE(0,0,0,0);
psd.PSDotMapping=PS_DOTMAPPING(
    0,
    PS_DOTMAPPING_ZERO_TO_ONE,
    PS_DOTMAPPING_ZERO_TO_ONE,
    PS_DOTMAPPING_ZERO_TO_ONE);
psd.PSCompareMode=PS_COMPAREMODE(
    PS_COMPAREMODE_S_LT | PS_COMPAREMODE_T_LT | PS_COMPAREMODE_R_LT | PS_COMPAREMODE_Q_LT,
    PS_COMPAREMODE_S_LT | PS_COMPAREMODE_T_LT | PS_COMPAREMODE_R_LT | PS_COMPAREMODE_Q_LT,
    PS_COMPAREMODE_S_LT | PS_COMPAREMODE_T_LT | PS_COMPAREMODE_R_LT | PS_COMPAREMODE_Q_LT,
    PS_COMPAREMODE_S_LT | PS_COMPAREMODE_T_LT | PS_COMPAREMODE_R_LT | PS_COMPAREMODE_Q_LT);

//------------- Stage 0 -------------
psd.PSRGBInputs[0]=PS_COMBINERINPUTS(
    PS_REGISTER_V0 | PS_CHANNEL_RGB | PS_INPUTMAPPING_SIGNED_IDENTITY,
    PS_REGISTER_T1 | PS_CHANNEL_RGB | PS_INPUTMAPPING_SIGNED_IDENTITY,
    PS_REGISTER_ZERO | PS_CHANNEL_RGB | PS_INPUTMAPPING_UNSIGNED_IDENTITY,
    PS_REGISTER_ZERO | PS_CHANNEL_RGB | PS_INPUTMAPPING_UNSIGNED_IDENTITY);
psd.PSAlphaInputs[0]=PS_COMBINERINPUTS(
    PS_REGISTER_V0 | PS_CHANNEL_ALPHA | PS_INPUTMAPPING_SIGNED_IDENTITY,
    PS_REGISTER_T1 | PS_CHANNEL_ALPHA | PS_INPUTMAPPING_SIGNED_IDENTITY,
    PS_REGISTER_ZERO | PS_CHANNEL_ALPHA | PS_INPUTMAPPING_UNSIGNED_IDENTITY,
    PS_REGISTER_ZERO | PS_CHANNEL_ALPHA | PS_INPUTMAPPING_UNSIGNED_IDENTITY);
psd.PSRGBOutputs[0]=PS_COMBINEROUTPUTS(
    PS_REGISTER_R1,
    PS_REGISTER_DISCARD,
    PS_REGISTER_DISCARD,
    PS_COMBINEROUTPUT_SHIFTLEFT_1 | PS_COMBINEROUTPUT_AB_MULTIPLY | PS_COMBINEROUTPUT_CD_MULTIPLY | PS_COMBINEROUTPUT_AB_CD_SUM);
psd.PSAlphaOutputs[0]=PS_COMBINEROUTPUTS(
    PS_REGISTER_R1,
    PS_REGISTER_DISCARD,
    PS_REGISTER_DISCARD,
    PS_COMBINEROUTPUT_IDENTITY | PS_COMBINEROUTPUT_AB_MULTIPLY | PS_COMBINEROUTPUT_CD_MULTIPLY | PS_COMBINEROUTPUT_AB_CD_SUM);
psd.PSConstant0[0] = 0x00000000;
psd.PSConstant1[0] = 0x00000000;

//------------- Stage 1 -------------
psd.PSRGBInputs[1]=PS_COMBINERINPUTS(
    PS_REGISTER_R1 | PS_CHANNEL_RGB | PS_INPUTMAPPING_SIGNED_IDENTITY,
    PS_REGISTER_T0 | PS_CHANNEL_RGB | PS_INPUTMAPPING_SIGNED_IDENTITY,
    PS_REGISTER_ZERO | PS_CHANNEL_RGB | PS_INPUTMAPPING_UNSIGNED_IDENTITY,
    PS_REGISTER_ZERO | PS_CHANNEL_RGB | PS_INPUTMAPPING_UNSIGNED_IDENTITY);
psd.PSAlphaInputs[1]=PS_COMBINERINPUTS(
    PS_REGISTER_R1 | PS_CHANNEL_ALPHA | PS_INPUTMAPPING_SIGNED_IDENTITY,
    PS_REGISTER_T0 | PS_CHANNEL_ALPHA | PS_INPUTMAPPING_SIGNED_IDENTITY,
    PS_REGISTER_ZERO | PS_CHANNEL_ALPHA | PS_INPUTMAPPING_UNSIGNED_IDENTITY,
    PS_REGISTER_ZERO | PS_CHANNEL_ALPHA | PS_INPUTMAPPING_UNSIGNED_IDENTITY);
psd.PSRGBOutputs[1]=PS_COMBINEROUTPUTS(
    PS_REGISTER_R0,
    PS_REGISTER_DISCARD,
    PS_REGISTER_DISCARD,
    PS_COMBINEROUTPUT_SHIFTLEFT_1 | PS_COMBINEROUTPUT_AB_MULTIPLY | PS_COMBINEROUTPUT_CD_MULTIPLY | PS_COMBINEROUTPUT_AB_CD_SUM);
psd.PSAlphaOutputs[1]=PS_COMBINEROUTPUTS(
    PS_REGISTER_R0,
    PS_REGISTER_DISCARD,
    PS_REGISTER_DISCARD,
    PS_COMBINEROUTPUT_IDENTITY | PS_COMBINEROUTPUT_AB_MULTIPLY | PS_COMBINEROUTPUT_CD_MULTIPLY | PS_COMBINEROUTPUT_AB_CD_SUM);
psd.PSConstant0[1] = 0x00000000;
psd.PSConstant1[1] = 0x00000000;

psd.PSC0Mapping = 0xffffffff;
psd.PSC1Mapping = 0xffffffff;
psd.PSFinalCombinerConstants = 0x000001ff;
