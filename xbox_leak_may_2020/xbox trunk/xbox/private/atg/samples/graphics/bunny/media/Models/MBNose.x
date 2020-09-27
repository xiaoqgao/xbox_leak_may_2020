xof 0302txt 0064
//
// DirectX file: \\Xbox\usr\DavMccoy\MouseBear\MBNose.x
//
// Converted by the PolyTrans geometry converter from Okino Computer Graphics, Inc.
// Date/time of export: 07/10/2001 16:35:20
//
// Bounding box of geometry = (-0.0465395,0.346781,0.304344) to (0.0465216,0.428487,0.330474).


template Header {
 <3D82AB43-62DA-11cf-AB39-0020AF71E433>
 WORD major;
 WORD minor;
 DWORD flags;
}

template Vector {
  <3D82AB5E-62DA-11cf-AB39-0020AF71E433>
 FLOAT x;
 FLOAT y;
 FLOAT z;
}

template Coords2d {
  <F6F23F44-7686-11cf-8F52-0040333594A3>
 FLOAT u;
 FLOAT v;
}

template Matrix4x4 {
  <F6F23F45-7686-11cf-8F52-0040333594A3>
 array FLOAT matrix[16];
}

template ColorRGBA {
  <35FF44E0-6C7C-11cf-8F52-0040333594A3>
 FLOAT red;
 FLOAT green;
 FLOAT blue;
 FLOAT alpha;
}

template ColorRGB {
 <D3E16E81-7835-11cf-8F52-0040333594A3>
 FLOAT red;
 FLOAT green;
 FLOAT blue;
}

template IndexedColor {
 <1630B820-7842-11cf-8F52-0040333594A3>
DWORD index;
 ColorRGBA indexColor;
}

template Boolean {
 <4885AE61-78E8-11cf-8F52-0040333594A3>
WORD truefalse;
}

template Boolean2d {
 <4885AE63-78E8-11cf-8F52-0040333594A3>
Boolean u;
 Boolean v;
}

template MaterialWrap {
 <4885AE60-78E8-11cf-8F52-0040333594A3>
Boolean u;
 Boolean v;
}

template TextureFilename {
 <A42790E1-7810-11cf-8F52-0040333594A3>
 STRING filename;
}

template Material {
 <3D82AB4D-62DA-11cf-AB39-0020AF71E433>
 ColorRGBA faceColor;
 FLOAT power;
 ColorRGB specularColor;
 ColorRGB emissiveColor;
 [...]
}

template MeshFace {
 <3D82AB5F-62DA-11cf-AB39-0020AF71E433>
 DWORD nFaceVertexIndices;
 array DWORD faceVertexIndices[nFaceVertexIndices];
}

template MeshFaceWraps {
 <4885AE62-78E8-11cf-8F52-0040333594A3>
 DWORD nFaceWrapValues;
 Boolean2d faceWrapValues;
}

template MeshTextureCoords {
 <F6F23F40-7686-11cf-8F52-0040333594A3>
 DWORD nTextureCoords;
 array Coords2d textureCoords[nTextureCoords];
}

template MeshMaterialList {
 <F6F23F42-7686-11cf-8F52-0040333594A3>
 DWORD nMaterials;
 DWORD nFaceIndexes;
 array DWORD faceIndexes[nFaceIndexes];
 [Material]
}

template MeshNormals {
 <F6F23F43-7686-11cf-8F52-0040333594A3>
 DWORD nNormals;
 array Vector normals[nNormals];
 DWORD nFaceNormals;
 array MeshFace faceNormals[nFaceNormals];
}

template MeshVertexColors {
 <1630B821-7842-11cf-8F52-0040333594A3>
 DWORD nVertexColors;
 array IndexedColor vertexColors[nVertexColors];
}

template Mesh {
 <3D82AB44-62DA-11cf-AB39-0020AF71E433>
 DWORD nVertices;
 array Vector vertices[nVertices];
 DWORD nFaces;
 array MeshFace faces[nFaces];
 [...]
}

template FrameTransformMatrix {
 <F6F23F41-7686-11cf-8F52-0040333594A3>
 Matrix4x4 frameMatrix;
}

template Frame {
 <3D82AB46-62DA-11cf-AB39-0020AF71E433>
 [...]
}

Header {
	1; // Major version
	0; // Minor version
	1; // Flags
}

Material xof_default {
	1.0;1.0;1.0;1.000000;;
	32.000000;
	0.700000;0.700000;0.700000;;
	0.0;0.0;0.0;;
}

Material Nose {
	1.0;1.0;1.0;1.000000;;
	25.000000;
	0.000000;0.000000;0.000000;;
	0.0;0.0;0.0;;
}

// Top-most frame encompassing the 'World'
Frame Frame_World {
	FrameTransformMatrix {
		1.000000, 0.0, 0.0, 0.0, 
		0.0, 1.000000, 0.0, 0.0, 
		0.0, 0.0, -1.000000, 0.0, 
		0.0, 0.0, 0.0, 1.000000;;
	}

Frame Frame_mousebearnose {
	FrameTransformMatrix {
		1.000000, 0.0, 0.0, 0.0, 
		0.0, 1.000000, 0.0, 0.0, 
		0.0, 0.0, 1.000000, 0.0, 
		0.0, 0.0, 0.0, 1.000000;;
	}

Frame Frame_mousebearnose_layer1 {
	FrameTransformMatrix {
		1.000000, 0.0, 0.0, 0.0, 
		0.0, 1.000000, 0.0, 0.0, 
		0.0, 0.0, 1.000000, 0.0, 
		0.0, 0.0, 0.0, 1.000000;;
	}

// Original object name = "mousebearnose_layer1"
Mesh mousebearnose_layer1 {
	37;		// 37 vertices
	0.046522;0.419040;0.309554;,
	-0.046540;0.419033;0.309563;,
	-0.020945;0.409882;0.329634;,
	-0.016608;0.402029;0.329982;,
	-0.007617;0.391271;0.329950;,
	-0.000000;0.384670;0.329560;,
	-0.008991;0.411329;0.330009;,
	0.000000;0.401629;0.330474;,
	0.007617;0.391271;0.329950;,
	0.008991;0.411329;0.330009;,
	0.016608;0.402029;0.329982;,
	0.020945;0.409882;0.329634;,
	-0.040341;0.393744;0.317335;,
	-0.023631;0.369050;0.315965;,
	-0.000000;0.346781;0.304344;,
	0.023630;0.369050;0.315965;,
	0.040336;0.393746;0.317332;,
	-0.016711;0.428485;0.316527;,
	0.016705;0.428487;0.316524;,
	0.000000;0.368551;0.319856;,
	0.000000;0.379374;0.327136;,
	-0.019164;0.379758;0.323326;,
	-0.014501;0.386277;0.327694;,
	-0.032136;0.397073;0.323761;,
	-0.025140;0.399447;0.327780;,
	-0.033434;0.414457;0.321472;,
	-0.025986;0.411779;0.327415;,
	0.025985;0.411779;0.327415;,
	0.033429;0.414459;0.321469;,
	0.010639;0.417504;0.327798;,
	0.012970;0.422548;0.323563;,
	-0.010639;0.417504;0.327798;,
	-0.012972;0.422548;0.323564;,
	0.019164;0.379758;0.323326;,
	0.032134;0.397073;0.323760;,
	0.014501;0.386277;0.327694;,
	0.025140;0.399447;0.327780;;

	63;		// 63 faces
	3;3,2,6;,
	3;7,3,6;,
	3;4,3,7;,
	3;8,4,7;,
	3;5,4,8;,
	3;7,6,9;,
	3;7,9,10;,
	3;8,7,10;,
	3;10,9,11;,
	3;14,13,19;,
	3;19,13,21;,
	3;19,21,20;,
	3;20,21,22;,
	3;20,22,5;,
	3;5,22,4;,
	3;13,12,21;,
	3;21,12,23;,
	3;21,23,24;,
	3;21,24,22;,
	3;22,24,3;,
	3;22,3,4;,
	3;12,1,25;,
	3;12,25,23;,
	3;23,25,26;,
	3;23,26,24;,
	3;24,26,2;,
	3;24,2,3;,
	3;11,9,29;,
	3;11,29,27;,
	3;27,29,30;,
	3;27,30,28;,
	3;28,30,18;,
	3;28,18,0;,
	3;9,6,29;,
	3;6,31,29;,
	3;31,30,29;,
	3;31,32,30;,
	3;32,18,30;,
	3;32,17,18;,
	3;2,31,6;,
	3;2,26,31;,
	3;26,32,31;,
	3;26,25,32;,
	3;25,17,32;,
	3;25,1,17;,
	3;14,19,15;,
	3;19,33,15;,
	3;15,33,16;,
	3;33,34,16;,
	3;16,34,28;,
	3;16,28,0;,
	3;19,20,33;,
	3;20,35,33;,
	3;33,35,36;,
	3;33,36,34;,
	3;34,36,27;,
	3;34,27,28;,
	3;20,5,35;,
	3;5,8,35;,
	3;35,8,10;,
	3;35,10,36;,
	3;36,10,11;,
	3;36,11,27;;

	MeshMaterialList {
		1;1;0;;
		{Nose}
	}

	MeshNormals {
		37; // 37 normals
		-0.572348;-0.156909;0.804859;,
		-0.541523;0.388853;0.745350;,
		-0.531771;-0.119366;0.838434;,
		-0.513425;0.374472;0.772118;,
		-0.397764;0.303803;0.865730;,
		-0.354205;-0.149557;0.923131;,
		-0.320662;-0.417180;0.850375;,
		-0.257737;-0.491607;0.831802;,
		-0.231868;0.697270;0.678271;,
		-0.213312;-0.292869;0.932055;,
		-0.192371;0.152634;0.969379;,
		-0.148285;0.678271;0.719694;,
		-0.119875;-0.066698;0.990546;,
		-0.084072;0.504831;0.859114;,
		-0.075562;-0.107322;0.991349;,
		-0.022219;0.183570;0.982755;,
		0.000000;-0.002878;0.999996;,
		0.000001;-0.272953;0.962027;,
		0.000003;-0.479720;0.877421;,
		0.000008;-0.553985;0.832527;,
		0.000010;-0.580296;0.814406;,
		0.026646;0.151954;0.988028;,
		0.075563;-0.107324;0.991349;,
		0.083986;0.452484;0.887809;,
		0.119881;-0.066701;0.990545;,
		0.148147;0.656967;0.739220;,
		0.174282;0.718321;0.673529;,
		0.192399;0.152649;0.969371;,
		0.213320;-0.292872;0.932052;,
		0.257815;-0.491593;0.831786;,
		0.320756;-0.417196;0.850331;,
		0.354278;-0.149556;0.923103;,
		0.397904;0.303881;0.865638;,
		0.513694;0.374631;0.771862;,
		0.532032;-0.119329;0.838273;,
		0.541867;0.389055;0.744994;,
		0.572685;-0.156819;0.804636;;

		63;		// 63 faces
		3;12,10,15;,
		3;16,12,15;,
		3;14,12,16;,
		3;22,14,16;,
		3;17,14,22;,
		3;16,15,21;,
		3;16,21,24;,
		3;22,16,24;,
		3;24,21,27;,
		3;20,7,19;,
		3;19,7,6;,
		3;19,6,18;,
		3;18,6,9;,
		3;18,9,17;,
		3;17,9,14;,
		3;7,0,6;,
		3;6,0,2;,
		3;6,2,5;,
		3;6,5,9;,
		3;9,5,12;,
		3;9,12,14;,
		3;0,1,3;,
		3;0,3,2;,
		3;2,3,4;,
		3;2,4,5;,
		3;5,4,10;,
		3;5,10,12;,
		3;27,21,23;,
		3;27,23,32;,
		3;32,23,25;,
		3;32,25,33;,
		3;33,25,26;,
		3;33,26,35;,
		3;21,15,23;,
		3;15,13,23;,
		3;13,25,23;,
		3;13,11,25;,
		3;11,26,25;,
		3;11,8,26;,
		3;10,13,15;,
		3;10,4,13;,
		3;4,11,13;,
		3;4,3,11;,
		3;3,8,11;,
		3;3,1,8;,
		3;20,19,29;,
		3;19,30,29;,
		3;29,30,36;,
		3;30,34,36;,
		3;36,34,33;,
		3;36,33,35;,
		3;19,18,30;,
		3;18,28,30;,
		3;30,28,31;,
		3;30,31,34;,
		3;34,31,32;,
		3;34,32,33;,
		3;18,17,28;,
		3;17,22,28;,
		3;28,22,24;,
		3;28,24,31;,
		3;31,24,27;,
		3;31,27,32;;
	}  // End of Normals
} // End of Mesh
} // End of frame for 'mousebearnose_layer1'
} // End empty node 'mousebearnose' frame
} // End of "World" frame
