L �7�<� P      .debug$S        F   �               @ B.rsrc$01        t  �   F      I   @  @.rsrc$02        �                @  @    	     obj\i386\projbld.res#    Microsoft CVTRES 5.00.2134.1              P �@  �b �X  �   x  �   �  �    �   � �               �   � �                    �    �               �   0 �              .    H �   ` �   x �   � �   � �   � �   � �   � �	    �
     �   8 �   P �   h �   � �   � �   � �   � �   � �   � �    �   ( �   @ �   X �   p �   � �   � �   � �   � �   � �     �    �    0 �!   H �"   ` �#   x �$   � �%   � �&   � �'   � �(   � �)    �*     �+   8 �,   P �-   h �.   � �                  � �   � �   � �   � �   � �    �   ( �   @ �	   X �
   p �   � �   � �   � �   � �   � �    	 �   	 �   0	 �   H	 �   `	 �   x	 �   �	 �                  �	 �               	  �	                 	  �	                 	  �	                 	  �	                 	   
                 	  
                 	   
                 	  0
                 	  @
                 	  P
                 	  `
                 	  p
                 	  �
                 	  �
                 	  �
                 	  �
                 	  �
                 	  �
                 	  �
                 	  �
                 	                    	                   	                    	  0                 	  @                 	  P                 	  `                 	  p                 	  �                 	  �                 	  �                 	  �                 	  �                 	  �                 	  �                 	  �                 	                    	                   	                    	  0                 	  @                 	  P                 	  `                 	  p                 	  �                 	  �                 	  �                 	  �                 	  �                 	  �                 	  �                 	  �                 	                    	                   	                    	  0                 	  @                 	  P                 	  `                 	  p                 	  �                 	  �                 	  �                 	  �                 	  �                 	  �                 	  �                 	  �                 	                    	                   	                    	  0                 	  @      5G              �#              �              ('              �              (              �              �              (              �              (              �              (              �              (              0              �              (              0              �              (              0              �              (              �              (              �              (              �              (              �              (              �              (              �              (              �              (              �              (              �              (              �              (              �              (              �              (              �              (              "                              "               "               "               0               0               0               "               "               "               "               "               "               "               "               "               "               "               "               "               "               d           R E G I S T R Y  T Y P E L I B   �	      �	       
  	    
  
    �       
      �      0
      @
             P
      `
            p
      �
             �
      �
      �
      0      �
      �
      �
      @      �
                !    P  "       #    0  $    `  %    @  &    P  '    p  (    `  )    p  *    �  +    �  ,    �  -    �  .    �  /    �  0    �  1    �  2    �  3    �  4    �  5    �  6    �  7       8      9    �  :       ;    0  <    �  =    @  >    P  ?    �  @    `  A    p  B       C    �  D    �  E      F    �  G    �  H       I    �  J    �  K    0  L    �	  M    �	  N    @  O    HKCR
{
	NoRemove '.asm' = s 'asmfile'
	{
		val 'Content Type' = s 'text/plain'
		'OpenWithList'
		{
			'devenv.exe'
		}
	}
	NoRemove '.s' = s 'asmfile'
	{
		val 'Content Type' = s 'text/plain'
		'OpenWithList'
		{
			'devenv.exe'
		}
	}
	NoRemove 'asmfile' = s 'Assembler Source'
	{
		val 'AlwaysShowExt' = s '1'
		'DefaultIcon' = s '%MODULE%,-2'
		'shell'
		{
			'Open'
			{
				'command' = s '"%COMMONIDE%devenv.exe" /dde'
				ddeexec = s 'Open("%%1")'
				{
					'application' = s 'devenv'
					'topic' = s 'system'
				}
			}
		}
	}

	NoRemove '.bsc' = s 'bscfile'
	{
	}
	NoRemove 'bscfile' = s 'Source Browser Database'
	{
		val 'NoOpen' = s ''
		'DefaultIcon' = s '%MODULE%,-7'
	}

	NoRemove '.c' = s 'cfile'
	{
		val 'Content Type' = s 'text/plain'
		'OpenWithList'
		{
			'devenv.exe'
		}
	}
	NoRemove 'cfile' = s 'C Source'
	{
		val 'AlwaysShowExt' = s '1'
		'DefaultIcon' = s '%MODULE%,-4'
		'shell'
		{
			'Open'
			{
				'command' = s '"%COMMONIDE%devenv.exe" /dde'
				ddeexec = s 'Open("%%1")'
				{
					'application' = s 'devenv'
					'topic' = s 'system'
				}
			}
		}
	}

	NoRemove '.cod' = s 'codfile'
	{
		val 'Content Type' = s 'text/plain'
		'OpenWithList'
		{
			'devenv.exe'
		}
	}
	NoRemove 'codfile' = s 'C/C++ Code Listing'
	{
		val 'AlwaysShowExt' = s '1'
		'DefaultIcon' = s '%MODULE%,-8'
		'shell'
		{
			'Open'
			{
				'command' = s '"%COMMONIDE%devenv.exe" /dde'
				ddeexec = s 'Open("%%1")'
				{
					'application' = s 'devenv'
					'topic' = s 'system'
				}
			}
		}
	}

	NoRemove '.cc' = s 'cppfile'
	{
		val 'Content Type' = s 'text/plain'
		'OpenWithList'
		{
			'devenv.exe'
		}
	}
	NoRemove '.cpp' = s 'cppfile'
	{
		val 'Content Type' = s 'text/plain'
		'OpenWithList'
		{
			'devenv.exe'
		}
	}
	NoRemove '.cxx' = s 'cppfile'
	{
		val 'Content Type' = s 'text/plain'
		'OpenWithList'
		{
			'devenv.exe'
		}
	}
	NoRemove 'cppfile' = s 'C++ Source'
	{
		val 'AlwaysShowExt' = s '1'
		'DefaultIcon' = s '%MODULE%,-3'
		'shell'
		{
			'Open'
			{
				'command' = s '"%COMMONIDE%devenv.exe" /dde'
				ddeexec = s 'Open("%%1")'
				{
					'application' = s 'devenv'
					'topic' = s 'system'
				}
			}
		}
	}

	NoRemove '.def' = s 'deffile'
	{
		val 'Content Type' = s 'text/plain'
		'OpenWithList'
		{
			'devenv.exe'
		}
	}
	NoRemove 'deffile' = s 'Export Definition File'
	{
		val 'AlwaysShowExt' = s '1'
		'DefaultIcon' = s '%MODULE%,-8'
		'shell'
		{
			'Open'
			{
				'command' = s '"%COMMONIDE%devenv.exe" /dde'
				ddeexec = s 'Open("%%1")'
				{
					'application' = s 'devenv'
					'topic' = s 'system'
				}
			}
		}
	}

	NoRemove '.dmp' = s 'dmpfile'
	{
		'OpenWithList'
		{
			'devenv.exe'
		}
	}
	NoRemove '.mdmp' = s 'dmpfile'
	{
		'OpenWithList'
		{
			'devenv.exe'
		}
	}
	NoRemove 'dmpfile' = s 'Crash Dump File'
	{
		'DefaultIcon' = s '%MODULE%,-13'
		val 'AlwaysShowExt' = s '1'
		'shell'
		{
			'Open'
			{
				'command' = s '"%COMMONIDE%devenv.exe" "%%1"'
			}
		}
	}

	NoRemove '.dsp' = s 'dspfile'
	{
		val 'Content Type' = s 'text/plain'
		'OpenWithList'
		{
			'devenv.exe'
		}
	}
	NoRemove 'dspfile' = s 'VC++ 6 Project'
	{
		'DefaultIcon' = s '%MODULE%,-1'
		'shell'
		{
			'Open'
			{
				'command' = s '"%COMMONIDE%devenv.exe" "%%1"'
			}
		}
	}

	NoRemove '.dsw' = s 'dswfile'
	{
		val 'Content Type' = s 'text/plain'
		'OpenWithList'
		{
			'devenv.exe'
		}
	}
	NoRemove 'dswfile' = s 'VC++ 6 Workspace'
	{
		'DefaultIcon' = s '%MODULE%,-9'
		'shell'
		{
			'Open'
			{
				'command' = s '"%COMMONIDE%devenv.exe" "%%1"'
			}
		}
	}

	NoRemove '.exp' = s 'expfile'
	{
	}
	NoRemove 'expfile' = s 'Exports Library File'
	{
		val 'NoOpen' = s ''
		'DefaultIcon' = s '%MODULE%,-14'
	}

	NoRemove '.h' = s 'hfile'
	{
		val 'Content Type' = s 'text/plain'
		'OpenWithList'
		{
			'devenv.exe'
		}
	}
	NoRemove '.hxx' = s 'hfile'
	{
		val 'Content Type' = s 'text/plain'
		'OpenWithList'
		{
			'devenv.exe'
		}
	}
	NoRemove '.hpp' = s 'hfile'
	{
		val 'Content Type' = s 'text/plain'
		'OpenWithList'
		{
			'devenv.exe'
		}
	}
	NoRemove 'hfile' = s 'C/C++ Header'
	{
		val 'AlwaysShowExt' = s '1'
		'DefaultIcon' = s '%MODULE%,-5'
		'shell'
		{
			'Open'
			{
				'command' = s '"%COMMONIDE%devenv.exe" /dde'
				ddeexec = s 'Open("%%1")'
				{
					'application' = s 'devenv'
					'topic' = s 'system'
				}
			}
		}
	}

	NoRemove '.i' = s 'ifile'
	{
		val 'Content Type' = s 'text/plain'
		'OpenWithList'
		{
			'devenv.exe'
		}
	}
	NoRemove 'ifile' = s 'Preprocessed C/C++ Source'
	{
		val 'AlwaysShowExt' = s '1'
		'DefaultIcon' = s '%MODULE%,-8'
		'shell'
		{
			'Open'
			{
				'command' = s '"%COMMONIDE%devenv.exe" /dde'
				ddeexec = s 'Open("%%1")'
				{
					'application' = s 'devenv'
					'topic' = s 'system'
				}
			}
		}
	}

	NoRemove '.idb' = s 'idbfile'
	{
	}
	NoRemove 'idbfile' = s 'VC++ Minimal Rebuild Dependency File'
	{
		val 'NoOpen' = s ''
		'DefaultIcon' = s '%MODULE%,-15'
	}

	NoRemove '.idl' = s 'idlfile'
	{
		val 'Content Type' = s 'text/plain'
		'OpenWithList'
		{
			'devenv.exe'
		}
	}
	NoRemove '.odh' = s 'idlfile'
	{
		val 'Content Type' = s 'text/plain'
		'OpenWithList'
		{
			'devenv.exe'
		}
	}
	NoRemove '.odl' = s 'idlfile'
	{
		val 'Content Type' = s 'text/plain'
		'OpenWithList'
		{
			'devenv.exe'
		}
	}
	NoRemove 'idlfile' = s 'Interface Definition Language File'
	{
		val 'AlwaysShowExt' = s '1'
		'DefaultIcon' = s '%MODULE%,-8'
		'shell'
		{
			'Open'
			{
				'command' = s '"%COMMONIDE%devenv.exe" /dde'
				ddeexec = s 'Open("%%1")'
				{
					'application' = s 'devenv'
					'topic' = s 'system'
				}
			}
		}
	}

	NoRemove '.ilk' = s 'ilkfile'
	{
	}
	NoRemove 'ilkfile' = s 'Incremental Linker File'
	{
		val 'NoOpen' = s ''
		'DefaultIcon' = s '%MODULE%,-17'
	}

	NoRemove '.inc' = s 'incfile'
	{
		val 'Content Type' = s 'text/plain'
		'OpenWithList'
		{
			'devenv.exe'
		}
	}
	NoRemove 'incfile' = s 'Include File'
	{
		val 'AlwaysShowExt' = s '1'
		'DefaultIcon' = s '%MODULE%,-8'
		'shell'
		{
			'Open'
			{
				'command' = s '"%COMMONIDE%devenv.exe" /dde'
				ddeexec = s 'Open("%%1")'
				{
					'application' = s 'devenv'
					'topic' = s 'system'
				}
			}
		}
	}

	NoRemove '.inl' = s 'inlfile'
	{
		val 'Content Type' = s 'text/plain'
		'OpenWithList'
		{
			'devenv.exe'
		}
	}
	NoRemove 'inlfile' = s 'C/C++ Inline File'
	{
		val 'AlwaysShowExt' = s '1'
		'DefaultIcon' = s '%MODULE%,-8'
		'shell'
		{
			'Open'
			{
				'command' = s '"%COMMONIDE%devenv.exe" /dde'
				ddeexec = s 'Open("%%1")'
				{
					'application' = s 'devenv'
					'topic' = s 'system'
				}
			}
		}
	}

	NoRemove '.lib' = s 'libfile'
	{
	}
	NoRemove 'libfile' = s 'Object File Library'
	{
		val 'AlwaysShowExt' = s '1'
		val 'NoOpen' = s ''
		'DefaultIcon' = s '%MODULE%,-16'
	}

	NoRemove '.lic' = s 'licfile'
	{
	}
	NoRemove 'licfile' = s 'License'
	{
		val 'NoOpen' = s ''
		'DefaultIcon' = s '%MODULE%,-8'
	}

	NoRemove '.lst' = s 'lstfile'
	{
		val 'Content Type' = s 'text/plain'
		'OpenWithList'
		{
			'devenv.exe'
		}
	}
	NoRemove 'lstfile' = s 'MASM Listing'
	{
		val 'AlwaysShowExt' = s '1'
		'DefaultIcon' = s '%MODULE%,-8'
		'shell'
		{
			'Open'
			{
				'command' = s '"%COMMONIDE%devenv.exe" /dde'
				ddeexec = s 'Open("%%1")'
				{
					'application' = s 'devenv'
					'topic' = s 'system'
				}
			}
		}
	}

	NoRemove '.mak' = s 'makfile'
	{
		val 'Content Type' = s 'text/plain'
		'OpenWithList'
		{
			'devenv.exe'
		}
	}
	NoRemove '.mk' = s 'makfile'
	{
		val 'Content Type' = s 'text/plain'
		'OpenWithList'
		{
			'devenv.exe'
		}
	}
	NoRemove 'makfile' = s 'Makefile'
	{
		val 'AlwaysShowExt' = s '1'
		'DefaultIcon' = s '%MODULE%,-10'
		'shell'
		{
			'Open'
			{
				'command' = s '"%COMMONIDE%devenv.exe" "%%1"'
			}
		}
	}

	NoRemove '.map' = s 'mapfile'
	{
		val 'Content Type' = s 'text/plain'
		'OpenWithList'
		{
			'devenv.exe'
		}
	}
	NoRemove 'mapfile' = s 'Linker Address Map'
	{
		val 'AlwaysShowExt' = s '1'
		'DefaultIcon' = s '%MODULE%,-8'
		'shell'
		{
			'Open'
			{
				'command' = s '"%COMMONIDE%devenv.exe" /dde'
				ddeexec = s 'Open("%%1")'
				{
					'application' = s 'devenv'
					'topic' = s 'system'
				}
			}
		}
	}

	NoRemove '.mdp' = s 'mdpfile'
	{
		'OpenWithList'
		{
			'devenv.exe'
		}
	}
	NoRemove 'mdpfile' = s 'VC++ 5 Workspace'
	{
		'DefaultIcon' = s '%MODULE%,-9'
		'shell'
		{
			'Open'
			{
				'command' = s '"%COMMONIDE%devenv.exe" "%%1"'
			}
		}
	}

	NoRemove '.ncb' = s 'ncbfile'
	{
	}
	NoRemove 'ncbfile' = s 'Visual C++ IntelliSense Database'
	{
		val 'AlwaysShowExt' = s '1'
		val 'NoOpen' = s ''
		'DefaultIcon' = s '%MODULE%,-18'
	}

	NoRemove '.obj' = s 'objfile'
	{
	}
	NoRemove 'objfile' = s 'Object File'
	{
		val 'AlwaysShowExt' = s '1'
		val 'NoOpen' = s ''
		'DefaultIcon' = s '%MODULE%,-19'
	}

	NoRemove '.pch' = s 'pchfile'
	{
	}
	NoRemove 'pchfile' = s 'Precompiled Header File'
	{
		val 'AlwaysShowExt' = s '1'
		val 'NoOpen' = s ''
		'DefaultIcon' = s '%MODULE%,-20'
	}

	NoRemove '.pdb' = s 'pdbfile'
	{
	}
	NoRemove 'pdbfile' = s 'Program Debug Database'
	{
		val 'AlwaysShowExt' = s '1'
		val 'NoOpen' = s ''
		'DefaultIcon' = s '%MODULE%,-21'
	}

	NoRemove '.rgs' = s 'rgsfile'
	{
		val 'Content Type' = s 'text/plain'
		'OpenWithList'
		{
			'devenv.exe'
		}
	}
	NoRemove 'rgsfile' = s 'Registration Script'
	{
		val 'AlwaysShowExt' = s '1'
		'DefaultIcon' = s '%MODULE%,-11'
		'shell'
		{
			'Open'
			{
				'command' = s '"%COMMONIDE%devenv.exe" /dde'
				ddeexec = s 'Open("%%1")'
				{
					'application' = s 'devenv'
					'topic' = s 'system'
				}
			}
		}
	}

	NoRemove '.sbr' = s 'sbrfile'
	{
	}
	NoRemove 'sbrfile' = s 'Source Browser Intermediate File'
	{
		val 'AlwaysShowExt' = s '1'
		val 'NoOpen' = s ''
		'DefaultIcon' = s '%MODULE%,-22'
	}

	NoRemove '.srf' = s 'srffile'
	{
		val 'Content Type' = s 'text/plain'
		'OpenWithList'
		{
			'devenv.exe'
		}
	}
	NoRemove 'srffile' = s 'Server Response File'
	{
		val 'AlwaysShowExt' = s '1'
		'DefaultIcon' = s '%MODULE%,-12'
		'shell'
		{
			'Open'
			{
				'command' = s '"%COMMONIDE%devenv.exe" /dde'
				ddeexec = s 'Open("%%1")'
				{
					'application' = s 'devenv'
					'topic' = s 'system'
				}
			}
		}
	}

	NoRemove '.tlh' = s 'tlhfile'
	{
		val 'Content Type' = s 'text/plain'
		'OpenWithList'
		{
			'devenv.exe'
		}
	}
	NoRemove 'tlhfile' = s 'Typelib Generated C/C++ Header File'
	{
		val 'AlwaysShowExt' = s '1'
		'DefaultIcon' = s '%MODULE%,-5'
		'shell'
		{
			'Open'
			{
				'command' = s '"%COMMONIDE%devenv.exe" /dde'
				ddeexec = s 'Open("%%1")'
				{
					'application' = s 'devenv'
					'topic' = s 'system'
				}
			}
		}
	}

	NoRemove '.tli' = s 'tlifile'
	{
		val 'Content Type' = s 'text/plain'
		'OpenWithList'
		{
			'devenv.exe'
		}
	}
	NoRemove 'tlifile' = s 'Typelib Generated C/C++ Inline File'
	{
		val 'AlwaysShowExt' = s '1'
		'DefaultIcon' = s '%MODULE%,-8'
		'shell'
		{
			'Open'
			{
				'command' = s '"%COMMONIDE%devenv.exe" /dde'
				ddeexec = s 'Open("%%1")'
				{
					'application' = s 'devenv'
					'topic' = s 'system'
				}
			}
		}
	}

	NoRemove '.vcproj' = s 'vcprojfile'
	{
		val 'Content Type' = s 'text/plain'
		'OpenWithList'
		{
			'devenv.exe'
		}
	}
	NoRemove 'vcprojfile' = s 'VC++ Project'
	{
		'DefaultIcon' = s '%MODULE%,-1'
		'shell'
		{
			'Open'
			{
				'command' = s '"%COMMONIDE%devenv.exe" "%%1"'
			}
		}
	}

	NoRemove CLSID
	{
		ForceRemove {F1C25864-3097-11D2-A5C5-00C04F7968B4} = s 'BuildPackage Class'
		{
			InprocServer32 = s '%MODULE%'
			{
				val ThreadingModel = s 'Apartment'
			}
		}
	}

	NoRemove TYPELIB
	{
		ForceRemove '{F1C25856-3097-11D2-A5C5-00C04F7968B4}' = s 'VC ProjBld Typelib'
		{
			'1.0' = s 'Microsoft Development Environment VC++ Project System Shell 7.0'
			{
				'0'
				{
					'win32' = s '%MODULE%'
					{
					}
					'FLAGS' = s '0'
					{
					}
					'HELPDIR' = s '%VCDIR%VCPackages'
					{
					}
				}
			}
		}
	}
}
HKLM
{
	%REGROOTBEGIN%
	NoRemove Packages
	{
		ForceRemove '{F1C25864-3097-11D2-A5C5-00C04F7968B4}' = s 'Visual C++ Project System'
		{
			val About = s 'Visual C++ Project System'
			val InprocServer32 = s '%MODULE%'
			Automation
			{
				val VCProjects = s ''
			}
			AutomationEvents
			{
				val VCProjectEngineEventsObject = s ''
			}
			SatelliteDll
			{
				val DllName = s 'VCProjectUI.dll'
				val Path = s '%VCDIR%VCPackages'
			}
		}
	}
	NoRemove InstalledProducts
	{
		ForceRemove VisualC++
		{
			val UseInterface = d '1'
			val Package = s '{F1C25864-3097-11D2-A5C5-00C04F7968B4}'
			val DefaultProductAttribute = s 'VC'
		}
	}
	NoRemove Projects
	{
		'{8BC9CEB8-8B4A-11D0-8D11-00A0C91BC942}' = s '#10006'
		{
			val Package = s '{F1C25864-3097-11D2-A5C5-00C04F7968B4}'
			val DisplayProjectFileExtensions = s '#10003'
			val DefaultProjectExtension = s 'vcproj'
			val PossibleProjectExtensions = s 'vcproj;dsp;mdp;mak'
			val ProjectTemplatesDir = s '%VCDIR%VCProjects'
			val ItemTemplatesDir = s '%VCDIR%VCNewItems'
			val DevStudioPackageID = d '4'
			AddItemTemplates
			{
				TemplateDirs
				{
					'{F1C25864-3097-11D2-A5C5-00C04F7968B4}'
					{
						'/1' = s '#10007'
						{
							val SortPriority = d '12'
							val TemplatesDir = s '%VCDIR%VCProjectItems'
						}
					}
				}
			}
			Filters
			{
				'/1' = s '#10005'
				{
					val CommonFindFilesFilter = d '1'
					val CommonOpenFilesFilter = d '1'
					val SortPriority = d 100
				}
				'/2' = s '#10011'
				{
					val CommonFindFilesFilter = d '1'
					val CommonOpenFilesFilter = d '1'
					val SortPriority = d 200
				}
				'/3' = s '#10012'
				{
					val CommonOpenFilesFilter = d '0'
					val SortPriority = d 300
				}
				'/4' = s '#10014'
				{
					val CommonOpenFilesFilter = d '0'
					val SortPriority = d 400
				}
			}
		}
		ForceRemove '{8BC9CEB9-8B4A-11D0-8D11-00A0C91BC942}' = s 'Exe Projects'
		{
			val Package = s '{F1C25864-3097-11D2-A5C5-00C04F7968B4}'
			val DisplayProjectFileExtensions = s '#10002'
			val DefaultProjectExtension = s 'exe'
			val PossibleProjectExtensions = s 'exe'
		}
		ForceRemove '{8BC9CEB9-9B4A-11D0-8D11-00A0C91BC942}' = s 'Crash Dump Projects'
		{
			val Package = s '{F1C25864-3097-11D2-A5C5-00C04F7968B4}'
			val DisplayProjectFileExtensions = s '#10004'
			val DefaultProjectExtension = s 'dmp'
			val PossibleProjectExtensions = s 'mdmp;dmp'
		}
		'{8BC9CEBA-8B4A-11D0-8D11-00A0C91BC942}' = s '#10008'
		{
			val Package = s '{F1C25864-3097-11D2-A5C5-00C04F7968B4}'
			AddItemTemplates
			{
				TemplateDirs
				{
					'{F1C25864-3097-11D2-A5C5-00C04F7968B4}'
					{
						'/3' = s '#10007'
						{
							val SortPriority = d '14'
							val TemplatesDir = s '%VCDIR%VCAddClass'
						}
					}
				}
			}
		}
		'{A2FE74E1-B743-11d0-AE1A-00A0C90FFFC3}'
		{
			NoRemove AddItemTemplates
			{
				NoRemove TemplateDirs
				{
					ForceRemove '{F1C25864-3097-11D2-A5C5-00C04F7968B4}'
					{
						'/1' = s '#10007'
						{
							val SortPriority = d '12'
							val TemplatesDir = s '%VCDIR%VCNewItems'
						}
					}
				}
			}
		}
		NoRemove '{FE3BBBB6-72D5-11d2-9ACE-00C04F79A2A4}'
		{
			NoRemove AddItemTemplates
			{
				NoRemove TemplateDirs
				{
					'{F1C25864-3097-11D2-A5C5-00C04F7968B4}'
					{
						'/1' = s '#10006'
						{
							val SortPriority = d '30'
							val TemplatesDir = s '%VCDIR%VCProjects'
						}
					}
				}
			}
		}
	}
	NoRemove NewProjectTemplates
	{
		NoRemove TemplateDirs
		{
			'{F1C25864-3097-11D2-A5C5-00C04F7968B4}' = s '#10006'
			{
				'/1' = s '#10006'
				{
					val SortPriority = d '30'
					val TemplatesDir = s '%VCDIR%VCProjects'
				}
			}
		}
	}
	NoRemove Services 
	{
		ForceRemove '{39642745-908C-11D3-B99A-00C04F685D26}' = s '{F1C25864-3097-11D2-A5C5-00C04F7968B4}'
		{
			val Name = s 'VC Edit & Continue Build Spawner'
		}
		ForceRemove '{39642745-908C-11D3-B99A-00C04F685D27}' = s '{F1C25864-3097-11D2-A5C5-00C04F7968B4}'
		{
			val Name = s 'VC Build Error Context'
		}
		ForceRemove '{531ADA6B-0EEA-11D3-8D31-00C04F8EEA30}' = s '{F1C25864-3097-11D2-A5C5-00C04F7968B4}'
		{
			val Name = s 'VC Project Engine'
		}
	}
	NoRemove AppCommandLine
	{
		ForceRemove DebugExe 
		{
			val Package = s '{F1C25864-3097-11D2-A5C5-00C04F7968B4}'
			val Arguments = s '*'
			val HelpString = s '#10000'
			val DemandLoad = d '1'
		}
		ForceRemove UseEnv
		{
			val Package = s '{F1C25864-3097-11D2-A5C5-00C04F7968B4}'
			val Arguments = s '0'
			val HelpString = s '#10001'
			val DemandLoad = d '1'
		}
	}
	NoRemove ToolsOptionsPages
	{
		NoRemove Projects
		{
			ForceRemove 'VCBuild' = s '#10009'
			{
				val Package = s '{F1C25864-3097-11D2-A5C5-00C04F7968B4}'
				val Page = s '{3284355B-AA45-11D2-835C-00C04F796961}'
			}
			ForceRemove 'VCDirectories' = s '#10010'
			{
				val Package = s '{F1C25864-3097-11D2-A5C5-00C04F7968B4}'
				val Page = s '{3284355C-AA45-11D2-835C-00C04F796961}'
			}
		}
	}
	NoRemove AutomationProperties
	{
		NoRemove Projects
		{
			ForceRemove VCGeneral
			{
				val Package = s '{F1C25864-3097-11D2-A5C5-00C04F7968B4}'
				val Name = s 'VCBuild'
			}
			ForceRemove VCDirectories
			{
				val Package = s '{F1C25864-3097-11D2-A5C5-00C04F7968B4}'
				val Name = s 'VCDirectories'
			}
		}
	}
	NoRemove Menus
	{
		val '{F1C25864-3097-11D2-A5C5-00C04F7968B4}' = s ',10013,1'
	}
	NoRemove HandleInComingCall
	{
		ForceRemove {4CE8C2C0-FDBB-11D2-B144-00C04F72DC32} = s 'IENCBuildSpawnerCallback'
	}
	%REGROOTEND%
}
   (   �           �&  �  �                �  �   �� �   � � ��  ��� ���   �  �   �� �   � � ��  ���    ���������������������      �      ����������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������� ������������������������������������������     ���������������������������������������������������������������������������������������������������������ڪ��������������������������������   ��������������݀   ����݇wwwww݇wwwww����������؈�����؈������� �����؈������� ������������݈����������������؈��������������؈�������������؈��������������       ����������wwwwww����������؈��������������݈��������������؈���������������������    ����    ������������݈�����������������ݍ��݈��������    ������������������������������������������      �      �      �      �      ���������� �  �      ������������t�@}��     �      ��      �      �      ػ������      �    ����      ��   ����   ����     ��  x   ���������������������  ������  �����������������ڪ��������������������������������   �������������ݏ�������ݏ�����ݏ������݈�������     �x�x�����0�0  �x�x�����0�0  �݈������     ���݈�������     �݈�������     �؈������     ��wwwwww}�wwwwwwp؈�������      �݈�������     �݈�������     �݈�������     �       ��      ݏ������݇wwp����؈�������     �������Ѝ������؍��     ���������       ��      ���������      �      �ݏ�����݇wwwww݇wwwww݋������wwwwww�      �0�0�wݏ�������   ���M�0�0www�wwwwwp�݇wwwww݇�wwww�������ػ����������݇www���݇wwwwp�������������`���wwwwp� �wp��      �      �   ��   ��      �      
���������������������������������   ������������݉�������ݏ�����ݏ������ݏ������ݏ������������ӻ�� ����������ӻ�� ���ݏ��������������ݏ������ݏ�����ݏ������ݏ������������ݏ������www�ww}�www wp�wwwwww��111111�ݏ������ݏ�����ݏ������ݏ�����ݏ������ݏ����؈������݈�����  �DD���� �DDp��������������������������q�ݍq���������� DD� ؈������݈����� ���������wwwwww݇wwwwp�ݏ�����ݏ�����ݏ�����ݏ�������������wwwwwwӻ�� ��ݏ������������݇ww`rLMӻ����������G�ݏ�����ݏ��������"83�݋������������ݏ������݇ww��p��������DO��������p�;��0�p݈����x�؈���x����;��0؈�;��0�������؈�����
���������������������������������   �������������݉�������ݏ�����ݏ������ݏ������ݏ��DOw�������3�� ��w�������3�� ���ݏ�������DDO����ݏ������ݏ�DD��ݏ������ݏDDDO��������ݏ������wwx��w}�wwp��wp�x�������""""#�݈������݀ ����ݏ������ݏ����݈�������DDDO����{{{{{�ݏ����� �����   ��wwp   ���������������������� ��}��}��� ������������������ݏ����� ���    �wwx���݇�   p�݇wwwwݏ����ݏ�����݋� � ���ffo�ؿ�{���3�� ��݇w��G�݋ffo��݇� g�b�3�� ����DDx��}ݏ������������⃈�݋������wwwwwpݏ��    �    �pظ���   ���������GOp�;0; �pݏ���tG���{xtG����;0; ��s;0; ���������{{{{�
���������������������������������   ��������   ���ݏ�������ݏ�����ݏ������ݏ������ݏ�������x��;���0����x���;���0���ݏ��������������ݏ������ݏ�����ݏ������ݏ������������ݏ�� ���ww���w}�ww���p�xxxx����2rrrr��݈�������0���݈�������    ��݈�������fffO������������{{{{p���DD��?���DDps7p����������������݈ � ��q�q���������  �DD�����  ����  p����wwwwp�x�p���݇�p�pp�""$DG��ݏp0ww�������ݏ�p���������������;���0��""'x���owk���݇�pv�&};���0��������Mݏ�p �����󂲈�?�ػ�w����x��ݏ������h�p����L�����DO��������pӻ��pݏ{{DD�x���DD�x�{s��������{{{{{x������
���������������������������������   ��������������ݏ�������ݏ�����ݏ������ݏ������ݏ��DOw����w��3�� H�w�������3����ݏ�������DDO����؈�������117D��ݏ������ݏDDDO�����x��ݏ��w�׈x���w}�HtDK�p�xww�����wx���݈�����݀;���ݏxx����݉pp��݈��������nfG����{{{{{���������������?���www{7p������������  ��݈s�0��p݈ww}x��� ������������ww����ww�����p�wwp  �݇�p�pp�/�/�Hxݏ�����L����݋�D��O���ffo�ظ�{���3���/�'�,�O݋oGo��݇�p�fg�3�� ���DG�.�Mݏ�LD�������   ػ������x��ݏ��7��0؈����pظ����������w���tGOp�;0; ��pݏ��hhhh�{thhhh���;0; �{s;0; ��������{{{{x
���������������������������������   ���������������ݏ�������ݏ��O��ݏ������ݏ������ݏ���������w�ӻ��D{��������ӻ�����ݏ�����������������������x����ݏ������ݏ������������ݏ����ׇw����}�GwD�� p�x������0�w���؈x���������݇ww����݇ww��݇ww����݇ww�����������{{{{{���D��;30��Dws;30����x�����������س�30�����q����������@�D� ������w��������������p�wwwwww݇����p�/�/�G��ݏww���O����ݏ�������������wx�ӻ����/�'���O�o�k���݇����p�ӻ��D�����.&ݏ��,D��������.��������w�wwwwwpݏ���~��gg��p���L�L����DO ��tG��p�;��0��pݏ{�wv�x���wv�x�{{;��0���;��0�{{{{{x�������
���������������������������������   ���������������݈�������ݏ��D��ݏ������ݏ������ݏD�DO�x�x�w��0�0(��x�x�����0�0��ݏ�������DDO�����w��������7D��ݏ������ݏDDDO��������ݏ�p���x�����}�tDD��`p�x���x�����x�������w���������w���� w���ݏ������ݏDD����{{{{{�����������3���0��w3{��0������������  ���;��3  ���x����� ������������������������p�wwx���݇�   p�/�/�Hx݇������O��L��݋�������O�O�wظ�{����0�0�/�'*,݋ffo��݇�   p��0�0����DDr��}ݏ��$�����������.��݋��������x��݈��>~�0ݎ����pظ���������� ��DD�wOp�3 ��pݏ�d��g���d��gx���3 ���3 �������������x
���������������������������������   ������������������������ݏ�DDO�ݏ������ݏ������ݏ������ww�w���38r(���w������3?����ݏ���������������w�����������ݏ������ݏ������������ݏ;����xx����}�ttG `p�x�������0燈�q�w������?{�������xw�����pw���ݏ�����ݏfd�����������������������?���w�w{7p�����x������� ��ز�33�����q����������@�   �����������������������p�x�p���݇�p�pp�""��� pw���O����ݏ�����t����H������݃3?���""r���owk���݇�p�pp�݃38�(������(��ݏ��(����"���..��x�w����x�����w�����w��p���L�L������P�hhho�p��33���pݏ{�{v{x��������{{x33x����33��{{{{{x�������
���������������������������������   ������������������������ݏ��O��ݏ������ݏ������ݏ��DO�ݏw���ݏx���ݏ������ݏ���ݏ�������DDO����؈�������117D��ݏww����ݏ�O��������ݏ����xx����}�ttGf`p�x��������~�s؏x����?�����x�������x������ݏ�w���ݏ�w���{{{{{�����������3�3�?���3�3{7p������������ ���+��0����w}����  ����� ��������������������������p�wwp  �݇�p�pp�ݏ�x��`��L�L��݋�� ���On$�wظ�wx�ݏ�����ݏ�(��݋oGo��݇�p�pp�ݏ�nbg���DDGp�ݏ�nbg���"���"����ݏ�����wwwwwp���w>�0���  �pؿ�������������wv��Op�����pݏ�h�����{hx{{x��������{{{{{x��������{{{{{x
���������������������������������   ��������؈��������������ݏ��O� ݏ���� �ݏ������ݏ�����ݏ�w���݋����ݏ������ݎ�����ݏ��������������ݏ������ݏ�����ݏ�����ݏ�����������ݏ�0����w�w���}�wDwf`p�x������0���q݈�������3�����ݏ������ݏ�����ݏ������ݏ�DO�����������{{����������������wwp����������������ز� 3����qwq���������@  ������������������݈�����wwwwww݇����p�ݏ����P��w�����wݏ��w��������������ݏ����wݏ����o�k���݇����p�ݏ�vf�������p�ݏ�vf��q������������w��������x���������p�p؈��L���������d��o��p�������pݏ�����������������������������������������
���������������������������������   ������������������������ݏ��O���ݏ�������ݏ��x���ݏD� �ݏ������ݏ��� �ݏ������ݏ��� �ݏ�������DO  ���ݏ������ݏ�D� �ݏww����ݏ� ��������ݏ��� ��w�w���}�wDwf`p�x���w�������s�ݏ�������?�� �ݏ������ݏ��� �ݏ������ݏ��� �{{{x�������������������w�wwwp�������������  �؈�� ��؇��}���   ��������x��������������������wwwwww݇wwwwp�ݏ�� ݀� � ݏ���� ݋�O�K������� عDDDD�ݏ���� ݏ�� ݋ffo��݇wwwwp�ݏ���� ��DDO  �ݏ���� �q��� ���.��������������x  ��DDD@��݈���  �����������������G  ������  ݇������ݏ{{���݇������ݏ{{���݇������ݏ{{���ڪ��������������������������������   ������������������������ݏ������ݏ�������ݏ������ݏ������ݏ������݋������ݏ������ݎ������ݏ��������������ݏ������ݏ������ݏ������ݏ�������������ݏ�������www���}�www   p�x�������0    �݈������݃������ݏ������ݏ������ݏ������ݏ�����݇������ݏ��������������w�wwwp�����������������{{�����q���q�������   DDDD@݇������ݏ���������������DDDDDDM�DDDDDD�ݏ���ݏ������ݏ������ݏ���O����������������ݏ������ݏ�����������DDDDDD�ݏ��������������ݏ������ݏx������������������wwww����DDD@���ݏ������������������;�h����������������{{x�������������{{x�������������{{x�����������ڪ��������������������������������   ������������������������݈������݈�������ݏ������ݏ������ݏ������ݏ������ݏ������ݏ������ݏ��������������ݏ������ݏ������ݏ������ݏ�������������ݏ�������wwwwww}�wwwwwwp�wwwwww���ݏ������ݏ������ݏ������ݏ������ݏ������ݏ������؈������؈������DDDDDDD�DDDDDDD����������������݈������݈�����������x���DDDDD@�؈������؈��������������DDDDDDM�DDDDDD�ݏ������ݏ������ݏ������݋�������������ؿ�����ݏ�����ݏ������݇������DDDDDD�ݏ��������������ݏ������ݏ������؈����������������������������ݏ�������DDDDDDM�DDDH�DM����������������݈������݈������݈������݈������݈������݈�����ڪ��������������������������������   �����������������������������������������݈������݈������݈������݈������݈������݈������݈�����؈�������݈������݈������݈������݈������؈�����݈�������wwwwww}�wwwwww}؈������Ј������݈������݈������݈������݈������݈������݈����������������������DDDDDDD�DDDDDDD�؈������؈������݈������݈������؈������       ����������������������������������������݈������݈������݈������݈�����؈������؈�����݈������݈����������������������݈������؈������݈������݈����������������������؈��������������݈�������DDDDDDM�DDDD�DM}؈�����؈�����������������������������������������������������ڪ��������������������������������   (       @         �                        �  �   �� �   � � ��  ��� ���   �  �   �� �   � � ��  ���                                   x�����          �����          �����        ������        �DDDD�        ������������ �DDDD������� ������������ �DDDD������� ��������3��� �DDDD������� ������������ �������3�38� �wwwwww����?� �����x�������� �������?����� wwwwwx��8�����  �������?�����  �����3;33����  �������������  �������8�����  �������?�����  �������?�����  �������������  DDDDDDDDDDDDD  DDDDDDDDDDDDD  DDDDDDDDDDDDD  DDDDDDDDDDDDD                                 ����� �� �� �� �� ��  �  �  �  �  �  �  �  �  �  �  �  �  �  �  �  �  �  �  �  �  �  �  �  ��������(                �                         �  �   �� �   � � ��  ��� ���   �  �   �� �   � � ��  ���                  ���    DD�   {���   DD��?�{����?�D��;30{�3���0w����?�{�3�3�?�wx������ ������ ������ DDDDDDD DDDDDDD��  �?  �?   ?                                  �   �   �   �            �      (         (       @         �                        �  �   �� �   � � ��  ��� ���   �  �   �� �   � � ��  ���                                        ���           ������         ���                  x�������    �www pwwww��   �wwwpwwwwww��   �wwwwwwwwww��   �wwwwwwwwww��   �wwwwwwwwww��   �wwwwwwwwww�    �wwwwwwwwww�    �wwwwwwwwww�    �wwwwwwwwww�    �wwwwwwwwww�    �wwwwwwwwww�    �wwwwwwwwww�    �wwwwwwwwww�    �wwwwwwwwww�   ��wwwwwwwwww�   ��wwwwwwwwww�   ��wwwwwwwww�   ��wwww �wwww�    ���� ������p         ��         �� ���          ����           ��              ��                          ���������� �� ?�� �  �  �  �  �  �  �  �  �  �  �  �  �  �                       �  � ?�� �� ��������         �       (       @                                  �  �   �� �   � � ��  ��� ���   �  �   �� �   � � ��  ���                 �wwwwwwwwwwwp   ������������p   ������������p   ������������p   ������������p   ������������p   ���DDDO�����p   ���DDDH��D��p   ��DH��DO�D��p   ��DO��DODDD�p   ��DO����DDD�p   ��DO�����D��p   ��DO�����D��p   ��DO��������p   ��DO��������p   ��DO�����D��p   ��DO�����D��p   ��DO��DODDD�p   ��DH��DODDD�p   ���DDDH��D��p   ���DDDO��D��p   ������������p   ������������p   ������������p   ����������      �����������x    ������������    ����������x     �����������     ����������      ����������         ?   ?   ?   ?   ?   ?   ?   ?   ?   ?   ?   ?   ?   ?   ?   ?   ?   ?   ?   ?   ?   ?   ?   ?   ?   ?      �  �  �  �  �(                �                         �  �   �� �   � � ��  ��� ���   �  �   �� �   � � ��  ���         wwwwwp �����p �����p �DO�Op �OD�Dp �OD�Op �O���p �OD�Op �OD�Dp �DO�Op �����p ����   ����p� ����x  �����  �  �  �  �  �  �  �  �  �  �  �  �  �  �  �  �           �      (         (       @                                  �  �   �� �   � � ��  ��� ���   �  �   �� �   � � ��  ���                 �wwwwwwwwwwwp   ������������p   ������������p   ������������p   ������������p   ������������p   �����DDD����p   �����DDD����p   ����D���D���p   ����D���D���p   ����D�������p   ����D�������p   ����D�������p   ����D�������p   ����D�������p   ����D�������p   ����D�������p   ����D���D���p   ����D���D���p   �����DDD����p   �����DDD����p   ������������p   ������������p   ������������p   ����������      �����������x    ������������    ����������x     �����������     ����������      ����������         ?   ?   ?   ?   ?   ?   ?   ?   ?   ?   ?   ?   ?   ?   ?   ?   ?   ?   ?   ?   ?   ?   ?   ?   ?   ?      �  �  �  �  �(                �                         �  �   �� �   � � ��  ��� ���   �  �   �� �   � � ��  ���         wwwwwp �����p �����p ��DO�p �D�D�p �D�D�p �D���p �D�D�p �D�D�p ��DO�p �����p ����   ����� ����  �����  � ��	�	�  �  �  �  �  �  �  �  �  �  �  �  �           �      (         (       @                                  �  �   �� �   � � ��  ��� ���   �  �   �� �   � � ��  ���                 �wwwwwwwwwwwp   ������������p   ������������p   ������������p   ������������p   ������������p   ����D���D���p   ����D���D���p   ����D���D���p   ����D���D���p   ����D���D���p   ����D���D���p   ����D���D���p   ����D���D���p   ����DO�DD���p   ����DDDDD���p   ����D�DDO���p   ����D�DD����p   ����D�������p   ����D�������p   ����D�������p   ����D�������p   ������������p   ������������p   ����������      �����������x    ������������    ����������x     �����������     ����������      ����������         ?   ?   ?   ?   ?   ?   ?   ?   ?   ?   ?   ?   ?   ?   ?   ?   ?   ?   ?   ?   ?   ?   ?   ?   ?   ?      �  �  �  �  �(                �                         �  �   �� �   � � ��  ��� ���   �  �   �� �   � � ��  ���         wwwwwp �����p �����p �D�D�p �D�D�p �D�D�p �D�D�p �D�D�p �DDO�p �D���p �D���p ����   ����� ����x  �����  �  �  �  �  �  �  �  �  �  �  �  �  �  �  �  �           �      (  	       (       @                                  �  �   �� �   � � ��  ��� ���   �  �   �� �   � � ��  ���                                                                                                                          �           ���          ���     �  ��������    �x����     �����������    ��    �����������     �    �����������         ����������        ����������         �������        wp     �������w      p      �������                                                                             �������������������������������������?�� � �  �  �  �  �  �  �  �  �  �  �  �  ?�  �  �� �� �� �������������(                �                         �  �   �� �   � � ��  ��� ���   �  �   �� �   � � ��  ���                            �     ���   ����   �   �����      ����   x�   ���p   x                           ��  ��� ��  �?  �  �  �  �  �  � �  �  �	 �?���@��� (       @         �                       ���                                      	 *�T@��U@�*�UU@���UU@���UU@���UP ���UU �� UT ��                 ����������������������������������������������?���x?� �� �?�  ?�  �  �  �  �  �  �  ?�  �  �� �� �� �������������         �  
    (        0   (       @                                  �  �   �� �   � � ��  ��� ���   �  �   �� �   � � ��  ���                                                                                                           P�P            �              ���            ��              ��                  �������               �         �������         �������         �������         �������       ������     P�P  �������   �   �������    ���  �������   ��   �������    ��   �������        �������                                                                                                                        ������������������������������������������߿��������߀ߏ���  ����������������������������������������(                �                         �  �   �� �   � � ��  ��� ���   �  �   �� �   � � ��  ���                                      �                  ���     ���     ���     ���    ���  �                                 ��  ��  ��  ��  ��  ��  ��  ��  ��  �  ��  ��  ��  ��  ��  ��  (       @                                ���                                p   �  �   �   @        P  *�  P  *�  P  *� pP �*��P �*� @P                              ������������������������������������������߿��������߀ߏ���  ����������������������������������������         �      (        0   (       @                                  �  �   �� �   � � ��  ��� ���   �  �   �� �   � � ��  ���                   �����������                   ����������    ����������    ����������    �DDDDDDDD�    ����������    ����������    �DDDDDDDD�    ����������    ����������    �DDDDDDDD�    ����������    ����������    �DDDDDDDD�    ����������    ����������    �DDDDDDDD�    ����������    ����������    �DDDDD����     �������        ��������p     �DDDDD�w      �������p      �������       �������                                                                      �����  �  �  �  �  �  �  �  �  �  �  �  �  �  �  �  �  �  �  �  �  �  �  ?�  �  �� �� �� �������������(                �                         �  �   �� �   � � ��  ��� ���   �  �   �� �   � � ��  ���                  ����   �DD�   ����   �DD�   ����   �DD�   ����   �D��   ���    �D�p   ���                           ����������  ���DD�DD�  ���������  ���?��������  (       @         �                       ���             ���������  �������  �������  �������  �������  ������� ?��� �� 5 �� �� ��                 ���������  �  �  �  �  �  �  �  �  �  �  �  �  �  �  �  �  �  �  �  �  �  ?�  �  �� �� �� �������������         �      (        0   (       @                                  �  �   �� �   � � ��  ��� ���   �  �   �� �   � � ��  ���                                                                                                                 F���  7wwp    l������p    F�����	���p2  ld�������p�  F�@�����	��p:2 Ld �������p��  @ ������	� *: #   ������ � *0  ������   * #�  9�����   *:0��������  F #���������l`::;;������F�@ #��������ld  :;;;������@   #��� ���d    ww� ���@     3330                                                                                                                     ��������������������������?��� ��  �          @  ���  �  p    �   �  �  � ��������������������������������(                �                         �  �   �� �   � � ��  ��� ���   �  �   �� �   � � ��  ���                          @      a� ;�0 F����� L@� *   �  # ;� F *0���l �� ��   3                                   ��  ��  ��  Ç  �       89       �  Ç  ��  �� ��  ��           �      (         (       @         �                        �  �   �� �   � � ��  ��� ���   �  �   �� �   � � ��  ���                                    x�����          �����          �DDD�        ������        ��DDD�        ������������x���DDD�����������������������DDD�����������������������DDD������������������������������������������������wwwwww�����������������������������������wwwww��������������������������������������wwwwwp���������� �������������� �������������� �������������� �������������� tDDDDDDDD@    @ tDDDDDDDDO���@ tDDDDDDDDH���@ tDDDDDDDDDDDDD@ wwwwwwwwwwwwwwp����� �� �� �� �� ��                                                                   �   �   �   �   �   �   �   �   �   (                �                         �  �   �� �   � � ��  ��� ���   �  �   �� �   � � ��  ���           ��     DO    ��    DO   ����DO������www�������www���������www���� ������ DDDDDDD DDDDDDD�  �  �  �                                      �   �   �            �      (         (       @         �                        �  �   �� �   � � ��  ��� ���   �  �   �� �   � � ��  ���                   �������������  �������������  �������������  ���     ����  ��x���������  ������~����  �����������  ������������  �����p����  ���wwww�����  ������������  ������������   p    f����� wwww�������������o�������������������������  �� ����������   ����������   wwpww��x���  ��ffo�p���  ������������  ��wwwww����  �������������  ��������     ������������   �����������p   �����������    ����������p    ����������     wwwwwwwwww   �   �   �   �   �   �   �   �   �   �   �   �   �   �   �               �   �   �   �   �   �   �   �   �  �  �  �  �  �  ?(                �                         �  �   �� �   � � ��  ��� ���   �  �   �� �   � � ��  ���                  ������ �    � ����g  �wwp~  ��hh��    �� ���������  � ����� wwwp� ����  ����p ���w  wwwwp ��  �   �   �   �   �   �   �   �       �   �   �   �  �  �           �      (         (       @         �                        �  �   �� �   � � ��  ��� ���   �  �   �� �   � � ��  ���                    �wwwwwwwwwp    ����������px��������������p��������p����������p���������p�www�����p���������p�www������p���������p�www����������p��������������p�������������������wwwwwwwwwwp���D� ����     ��l�,d���     ��l�$DO���     ��|�&L@���     ��o�"�@���     ����&l����     �����d`���     ��o$�b���     ��hb""o���     ���hF&����     ����f��        ���������      ��������p      ��������       �������p       �������        wwwwwwww        ��  ��                                                        �  �  �  �  �  �  �  �  �  �  �  �  �  �  ?�  �  ��(                �                         �  �   �� �   � � ��  ��� ���   �  �   �� �   � � ��  ���           p       x�����  x�x�x�{�x��x��x����x�����{�wwwwwp��D�   �nh�   ����   {����   ����   wwwww   ��  �   �                                                          �      (         (       @         �                        �  �   �� �   � � ��  ��� ���   �  �   �� �   � � ��  ���                                       ��������       ��������       ���DDO��       ��������       ���D����       ��������       �L�DD���       �������� wwwwww���DDD�� �"������������ ���������DDO�� �������������� �������L�DDD��  wwwwww��������       ���DDD��  �������������  ������L�DD�wp  �DDDG�������p  ������������   �����������p   �����wwwwww    ������O�p      ������O�p      ������O�p      ������O�p      ������O�p      �DDDDDO�p      ��������p       x�������p       wwwwwwwp     ������ �� �� �� �� �� �� �� �  �  �  �  �  �  �  �  �  �  �  �  �  �  ?� �� �� �� �� �� �� �� �� �(                �                         �  �   �� �   � � ��  ��� ���   �  �   �� �   � � ��  ���            ����   ��D�   ����   ��D��������DDG��D�O������L����D�O������L��wwwpL����� O����� DDDDD� ������ wwwwwp �   �   �   �   �                                       �           �      (         (       @         �                        �  �   �� �   � � ��  ��� ���   �  �   �� �   � � ��  ���    wwwwwwwwwwwww   x������������     ����������   �30����������  �0  ���������� ��3�������������3� ������ �0�  ������;3   ������?�0��30�����;�0��30������s??3   w���� ;�0�  ����������3 ���w���� ��3	������3�0  �����w��  �30���������  3 	����������   ������������   ������������   	�����������   p�����������   	����������   𙙙�������   �	���������   �������www   ����������p   �����������    ����������p    ����������     ���������p     wwwwwwwwww   �   �   �   �   �   �   �   �                   �   �   �   �   �   �   �   �   �   �   �   �   �   �   �  �  �  �  �  �  ?(                �                         �  �   �� �   � � ��  ��� ���   �  �   �� �   � � ��  ���         0�0wwww������3�� ���;�p�0��3�� ������	�0�0)��� s36���  ������  ����� 	�� �� � �ww � ��p ����w  wwwwp ��  �   �               �   �   �   �   �   �   �   �  �  �           �      (         (       @         �                        �  �   �� �   � � ��  ��� ���   �  �   �� �   � � ��  ���   wwwwwwwwwwwww   x������������   ������������   x������������   ������������   x������������   ������������   x������������   ������������   x�         ��   ������������   x������������   ������������   x������������   ������������   x������������   ������������   x�         ��   �����O������   x�����D������   ����OOO�����   x�����H������   ������������   x�����H������   ������������   x���������www   �����������p   x�����������    ����������p    x����������     ���������p     wwwwwwwwww    �  �  �  �  �  �  �  �  �  �  �  �  �  �  �  �  �  �  �  �  �  �  �  �  �  �  �  �  �  �  ?�  �  �(                �                         �  �   �� �   � � ��  ��� ���   �  �   �� �   � � ��  ���          wwwwwwp �����p      �p ������p ������p ������p      �p �O���p x�D���p OOO��p x�H���p ����wp x�H���  ����p  wwwww  ��  �  �  �  �  �  �  �  �  �  �  �  �  �  �  �           �      (          (       @         �                        �  �   �� �   � � ��  ��� ���   �  �   �� �   � � ��  ���    wwwwwwwwwwwww   x������������   ������������   ������  ���   ������30���   ����  �0  ��   ���� ��3�   ���������3�   �����0� ��   ���;3  �   �0�?�0��30�   x;;�0��30�   �3��s??3  �  ;��;�0� ��   3���󿿿��3�   ���� ��3�   p����3�0  ��   �����30���  ���`���3 ��� �f�������� �P����`���������U��f������� ��P����`������� �U���������  ��������������  ��������www   �����������p   �����������    ����������p    ����������     ���������p     wwwwwwwwww   �   �   �   �   �   �   �   �   �   �   �   �   �   �   �   �   �   �   �   �   �       �   �   �   �   �  �  �  �  �  �  ?(                �                         �  �   �� �   � � ��  ��� ���   �  �   �� �   � � ��  ���         wp0�0  �󻻳 �3��  �;�p�0 3��   0󻻳 ��0�0' �s36�  ����� � ����P����� �`�ww  ���p ����w  wwwwp ��  �  �   �   �   �   �   �   �   �   �       �   �  �  �           �  !    (  "       (       @         �                        �  �   �� �   � � ��  ��� ���   �  �   �� �   � � ��  ���   wwwwwwwwwwwww   x������������   ������������   ������������   ������������   ������������   ������������   ������������   ������������   ������������   �p   �   ��   ��ww x����   ��       ��   �������w�   ��       ��   ���� �����   �p   �   ��   ������������   ������������   ������������   ������������   ������������   ������������   ������������   ������������   ���������www   �����������p   �����������    ����������p    ����������     ���������p     wwwwwwwwww    �  �  �  �  �  �  �  �  �  �  �  �  �  �  �  �  �  �  �  �  �  �  �  �  �  �  �  �  �  �  ?�  �  �(                �                         �  �   �� �   � � ��  ��� ���   �  �   �� �   � � ��  ���          wwwwww ������ ������   � �� ������    ���    � ������   � �� ������ ����ww ����p ����w  wwwwp ��  �   �   �   �   �               �   �   �   �   �  �  �           �  #    (  $       (       @         �                        �  �   �� �   � � ��  ��� ���   �  �   �� �   � � ��  ���                   ������������   ������������   ������������   ����   ������������   ������������      ���������  ���7 ���  �����0�������  ����7��  �����0�������  ����7�������  �����0�������  ����3��  �    0�������   ���� ��  �������������  �������������   ���� ��������      ��   ������������   ����   ������������   ������������   ���������p     ����������p   ����������    ���������xp    ���������w     ���������p     wwwwwwwwwp   �  �  �  �  �  �  �  �  �  �  �  �  �  �  �  �  �  �  �  �  �  �  �  �  �  �  �  �  �  �  �  ?�  (                �                         �  �   �� �   � � ��  ��� ���   �  �   �� �   � � ��  ���                  ������  ����� ����������������� �� ������������ �������  �� ����   ����p ����w  wwwwp ��  �   �   �   �                       �   �   �   �  �  �           �  %    (  &       (       @         �                        �  �   �� �   � � ��  ��� ���   �  �   �� �   � � ��  ���   wwwwwwwwwwwwp  ������������p  ������������p  ������������p  ������������p  ������������p  ������������p  ������������p  ������������p  �����������p  ��0���������p  �;��������p  �3����������p  ;���������p   3�����������p  ����������p  �����������p  ����������p  ����`��������p ��f�������p �P����`�������p�U��f������p ��P����`������p �U��������p  �������������p  �������wwwp   �����������   ����������p   ����������    ���������xp    ���������w     wwwwwwwwwp   �  �  �  �  �  �  �  �  �  �  �  �  �  �  �  �  �  �  �  �  �     �  �  �  �  �  �  �  �  �  ?�  (                �                         �  �   �� �   � � ��  ��� ���   �  �   �� �   � � ��  ���          wwwwww ������ ������ ������  ����  ;����  ����� ������ � ����P����� �`���  ���ww ����p ����w  wwwwp ��  �   �   �   �   �   �   �   �   �       �   �   �  �  �           �  '    (  (       (       @         �                        �  �   �� �   � � ��  ��� ���   �  �   �� �   � � ��  ���   wwwwwwwwwwwwp  ������������p  ������������p  ������������p  ������������p  �      ����p  �x���������p  ����������p  ����������p  ��D�O�����p  ��D�O�����pwww�D�O�����p����D�O�����p����D�O�����p����DD������p�D��D�������p�D��D�� ����p�D�����������p�D����������p�D�wwwww������p�DD�����������p�D������������p�D��ww��������p������������p����w���������pwwww������wwwp  �����������   ����������p   ����������    ���������xp    ���������w     wwwwwwwwwp   �  �  �  �  �  �  �  �  �  �  �  �  �  �  �  �  �  �  �  �  �  �  �  �  �  �  �  �  �  �  �  ?�  (                �                         �  �   �� �   � � ��  ��� ���   �  �   �� �   � � ��  ���  wwwwwwp �����p p   �p �����pp�OO�p��OO�p��D��p��O��p��O��p�����p�   �p�����pwww�wp �����  ����p  wwwww  �  �  �  �  �  �  �  �  �  �  �  �  �  �  �  �           �  )    (  *       (       @         �                        �  �   �� �   � � ��  ��� ���   �  �   �� �   � � ��  ���    wwwwwwwwwwwww   x������������   ������������   ������������   ������������        wwww��   ������������   ������������  �������www��  �������������  �������������  ��������www�� �������������� ���������������� �����www��� �����������   �����������   �����www��   �����������   �����������   �����www��   �����������   ��� �������   ���wwwww��    � ���������   ��������www   ����������p   �����������    ����������p    ����������     ���������p     wwwwwwwwww   �   �   �   �   �   �   �   �   �   �   �   �   �   �             �   �   �   �   �   �   �   �   �   �  �  �  �  �  �  ?(                �                         �  �   �� �   � � ��  ��� ���   �  �   �� �   � � ��  ���          wwwwww ������    ���� ���w�� ������ ���w������� w�� ��� w��  ����  www   ���p ����w  wwwwp ��  �   �   �   �   �   �           �   �   �   �   �  �  �           �  +    (  ,       (       @         �                        �  �   �� �   � � ��  ��� ���   �  �   �� �   � � ��  ���   wwwwwwwwwwwww   x������������   ������������   x������������   ������������   x�wwwwwwww��   ������������   x������������   �wwwwwwww��   x������������   ������������   x�wwwwwwww��   ������������   x������������   �wwwwwwww��   x������������   ������������   x�wwwwwwww��   ������������   x������������   �wwwwwwww��   x������������   ������������   x�wwwwwwwwx��   ������������   x���������www   �����������p   x�����������    ����������p    x����������     ���������p     wwwwwwwwww    �  �  �  �  �  �  �  �  �  �  �  �  �  �  �  �  �  �  �  �  �  �  �  �  �  �  �  �  �  �  ?�  �  �(                �                         �  �   �� �   � � ��  ��� ���   �  �   �� �   � � ��  ���          wwwwwwp �����p x�����p �ww�p x�����p �ww�p x�����p �ww�p x�����p �ww�p x�����p �ww�wp x�����  ����p  wwwww  ��  �  �  �  �  �  �  �  �  �  �  �  �  �  �  �           �  -    (  .       MSFT      	      A         	               D   b      ����       �         P       d   �   ,  �  �  X  �     l  �  ����   H     ����   T     ����   ����    ����   �  �   ����   p  �   ����   p     ����   p  �  ����   `  �   ����   �  p   ����   ����    ����   `  T   ����   �  $   ����   ����    ����   ����    ����   4"  �     `         ,                   �   @         `           ���� �             ���� ! <  �  �                             ����    �       ����        ����       ����        ���� ! D  �   �                             ����    �      ����        ����       ����        ���� ! �  �   �                             ����    $      ����        ����       ����        ���� ! �  �   �                             ����    �      ����        ����       ����        ���� ! $   �   �                             ����    l      ����        ����       ����        ���� ! �   �   �                             ����          ����        ����       ����        ����4" �!  �   �                             �   @  �      `           ���� $             ����4" ,"  �  �                            �   @  @      ����        ���� 4             ������������x   ���������������������   �   �   ����������������������������`       ����������������H      ��������������������0   VX��0��� �Oyh���������e�w�|Q���  �w<���������c�w�|Q���  �w<���������d�w�|Q���  �w<���������0     �      F   ����      �      F   ����ơ�$�) C�K�k?%�@    ����ǡ�$�) C�K�k?%�@�  ����&p6��3��R �O�ͷ   ����      x   `          - stdole2.tlbWWWt   ������������  �  �������������������������   l  ���������  �  �������������  �������������  ����$  �  �������������  �����  �����  l  D  ����  �����  ���������  ��������   h  ����`  �������������  �  �������������    �  �����  l  ������������X  ������������@  ���������   �   �����  ,  �  �����  x  �  ���������  ����    ���������  ����������������   ����  <  �  �����  P  ���������  ��������������������|  ����   ���������  H   X  �  ���������������������������� ZnVCProjectLibrary    ���� 8�TVCProjectConfigurationProperties    ���� �hOutputDirectoryW�������� ��ValW    ���� ��IntermediateDirectoryWWWd   ����8͙ConfigurationTypesWWd   ����0�QtypeUnknownWd   ����0�typeApplicationWd   ����0�atypeDynamicLibraryWWd   ����0dTtypeStaticLibraryWWWd   ����0��typeGenericW    ���� �lConfigurationTypeWWW��������
 ��ConfigTypeWW    ���� � BuildBrowserInformationW�������� zzBscW�   ����(-BuseOfMfc�   d  0lNuseMfcStdWin�   ����0��useMfcStatic�   ����0�|useMfcDynamicWWW�������� =�useMfcWW,  ����(useOfATL,  ����01useATLNotSet,  ����0i�useATLStatic,  8  0��useATLDynamicWWW��������  xuseATLWW    ����  ӺATLMinimizesCRunTimeLibraryUsage����$   ��UseCRTWW�  ����8Q#charSetW�  �   0��charSetNotSetWWW�  ����0�dcharSetUnicodeWW�  ����0"charSetMBCSW    ���� ��CharacterSet��������
 b2optSettingWW    ���� ��ManagedExtensionsWWW�������� 8
ManagedW    �   ��DeleteExtensionsOnCleanW�������� O�ExtW    ���� �hWholeProgramOptimization����<   ��Optimize    ���� �]CommandW    ���� t�WorkingDirectory    ���� e�CommandArguments    ���� ��AttachWW�  ����8%�RemoteDebuggerTypeWW�  ����0fDbgLocal�  ����	0"�DbgRemoteWWW�  ����0��DbgRemoteTCPIPWW    ���� ��RemoteWW    ���� ��RemoteMachineWWWX  �  8�TypeOfDebuggerWWX  �  0��DbgNativeOnlyWWWX  d   0�;DbgManagedOnlyWWX  ����0��DbgMixedX  ����0�:DbgAutoW    <   ]tDebuggerType        ��RemoteCommandWWW    ���� >�HttpUrlW    ���� @�PDBPathW    ���� �$SQLDebugging�  ����8 VCFileConfigurationPropertiesWWW�  T   b�ExcludedFromBuildWWW   ����8I`IVCBuildOptionsPageW   ���� 3�BuildLogging����   T�pbLogWWW   ���� �YBuildTimingW�������� �pbTimeWW   ���� ��CPPExtensionsWWW�������� ؎pbstrExtensionsWL Microsoft Development Environment VC++ Project System Shell 7.0 Type LibraryWW VCProject.dllW+ Visual C++ Project Configuration PropertiesWWW @ �  d    @    @ �  �    @      ,   @0     �   @@     �   @P     X   @`    >   Created by MIDL version 6.00.0347 at Mon Apr 29 23:14:16 2002
 96�<WW [ WW       ����0   D       H   L      P
  <    �     L D        �����������������      d   
   <   �      D !         �����������������   �����   <   �    $ L D        �����������������      d   
   <   �    ( D !        �����������������   �����   <   �    , L D        �����������������     d  
   <   �    0 D !        �����������������     ����   <   �    4 L D        �����������������     �  
   <   �    8 D !        �����������������   �����   <   �    < L D	        �����������������  (     
   < 	  �    @ D !        �����������������      ����   < 
  �    D L D        �����������������  8   �  
   <   �    H D !
        �����������������  0   ����   <   �    L L D        �����������������     �  
   <   �    P D !        �����������������   �����   <   �    T L D        �����������������  H   T  
   <   �    X D !        �����������������  @   ����   <   �    \ L D        �����������������     �  
   <   �    ` D !        �����������������   �����   <   �    d L D        �����������������      �  
   <   �    h D !        �����������������   �����   <   �    l L D        �����������������     �  
   <   �    p D !        �����������������   �����   <   �    t L D        �����������������.      d   
   <   �    x D !        �����������������.   �����   <   �    | L D        �����������������.      d   
   <   �    � D !        �����������������.   �����   <   �    � L D        �����������������.      d   
   <   �    � D !        �����������������.   �����   <   �    � L D        �����������������.     d   
   <   �    � D !        �����������������.   �����   <   �    � L D        �����������������.  X   d   
   <   �    � D !        �����������������.  P   ����   <    �    � L D!        �����������������.      d   
   < !  �    � D !         �����������������.   �����   < "  �    � L D#        �����������������.  h   d   
   < #  �    � D !"        �����������������.  `   ����   < $  �    � L D%        �����������������.      d   
   < %  �    � D !$        �����������������.   �����   < &  �    � L D'        �����������������.      d   
   < '  �    � D !&        �����������������.   �����   < (  �    � L D)        �����������������.      d   
   < )  �    � D !(        �����������������.   �����   < *  �    � L D+        �����������������.     d   
   < +  �    � D !*        �����������������.   �����   �  �  �  �  �  �  �  �  �  �  �  �  �  �  �  �  �  �  �  �  �  �  �.  �.  �.  �.  �.  �.  �.  �.  �.  �.  �.  �.  �.  �.  �.  �.  �.  �.  �.  �.  �.  �.  H   H   t   t   D  D  |  |  �  �  $  $  �  �  <  <  l  l  �  �  �  �            <  <  X  X  �  �  �  �  �  �  �  �  �  �  �  �  �  �      <   x   �   �   ,  h  �  �    X  �  �    H  �  �  �  8  t  �  �  (  d  �  �    T  �  �    D  �  �  �  4  p  �  �  $	  `	  �	  �	  
  �   (    �     4    �    �������������3  (   �     4   �    �������������3  (   �     4   �    �������������3  (   �     4   �    �������������3  (   �     4 
  �    �������������3     @  @  @  @  @�   �   �     ,      (   P   x   �   x   (    �     4    �    �������������3  (   �     4   �    �������������3  (   �     4   �    �������������3     @  @  @�  �  �      (   P   x   (    �     4    �    �������������3  (   �     4   �    �������������3  (   �     4   �    �������������3     @  @  @8  P  h      (   P   x   (    �     4    �    �������������3  (   �     4   �    �������������3  (   �     4   �    �������������3     @  @  @�    $      (   P   x   (    �     4    �    ������������&/  (   �     4   �    ������������'/  (   �     4   �    ������������(/     @  @  @�  �  �      (   P   �   (    �     4    �    ������������)/  (   �     4   �    ������������*/  (   �     4   �    ������������+/  (   �     4   �    ������������,/     @  @  @  @   <  X  l      (   P   x   x   <    �     L D        �����������������        
   <   �      D !         �����������������   �����   �  �            <   h  <    �     L D        �����������������      x  
   <   �      D !         �����������������    �����   <   �    $ L D        �����������������      �  
   <   �    ( D !        �����������������    �����   <   �    , L D        �����������������       �  
   <   �    0 D !        �����������������    �����   �   �   �   �   �   �   `  `  �  �  �  �      <   x   �   �   ,  MSFT      	      A                                 ����       �         X       d   �   ,  �  �  X  d  �  ����   0     ����   H     ����   �  @   ����      �   ����   �  P  ����   d     ����   d  t  ����   �
  �   ����   �      ����   ����    ����   �  T   ����   �  $   ����   ����    ����   ����    ����   %"         ����                           `      $       ����        ����                  ����4"       �         	                   �   @  @       h   Z      ���� @             ����%" �      ����                           �      `      ����        ����                 ����4" �     (                            �   @  |      |   l      ���� H             ����%" �      ����                           �      �      ����        ����                  ����4" �  �                                @        �   �      ���� 8             ����%" �      ����                                 \      ����        ����      0           ����8     �   ��������������������  �   �   �   `   �   ����������������x   ��������������������H      ��������������������0   ��N�k�L�]���U����������e�w�|Q���  �w<���������c�w�|Q���  �w<���������d�w�|Q���  �w<���������e]->�� �Oh�b    ����0     �      F   ����      �      F   ����e]->�� �Oh�bd   ������!PA�� �Oh�b�   ������!PA�� �Oh�b,      ��!PA�� �Oh�b�  ������!PA�� �Oh�b�  ����dX��0��� �Oyh�X  ����        �      F   ����d      ��������,     ���������     ��������      ��������      �        8  x          - stdole2.tlbWWW��������H  �  ������������������������������������$   �����������������     �����  �����������������������������   ����������������������������@   �����������������   ������������������������������������|      �����������������  �  <  ����������������������������`   ��������������������������������`  ����������������,  �����������������   ������������$  ��������������������������������  ���������������������������������������������  �����   �   \  ���������������������������������������������������� 5�VCPrivateProjectLibraryW    ����8�bFileNodePropsWWWd   ����8%�Filed   ���� ��Name�������� ��pVald   ���� +FullPathd   ���� מRelativePathd   ���� ��DeploymentContentWWWd   ���� ,Extender����p    MbstrName�������� �ppDispWWd   ���� sBExtenderNamesWWW��������	 *pvarNamesWWWd   ���� R#ExtenderCATIDWWW��������	 �pbstrGuidWWW�   ����8MbFolderNodePropsW,  ����8�;FilterWW,  P   
 ��ParseFilesWW�������� 9pbParseW,  ���� ;�SourceControlFilesWW�������� �pbSCCWWW�  ����8�ProjectNodeProps�  ����
8��_VCProjectWW�  ���� [�ProjectFileW�  ���� �.ProjectDependenciesWX  ����8��BuildPackageT Microsoft Development Environment VC++ Project System Shell 7.0 Private Type LibraryWW VCProject.dllW VC File InterfaceW Filter InterfaceWW Visual C++ Project InterfaceWW @ � @ � 	@	 	� @ � >   Created by MIDL version 6.00.0347 at Mon Apr 29 23:14:18 2002
 ;6�<WW [ WW       ����0   D       H   L      (  <    �     L D         ����������������V      `   
   <   �      L D        ����������������W      `   
   <   �    $ L D        ����������������X      `   
   <   �    ( D !        ����������������X   �����   <   �    , L D        ����������������Y     `   
   <   �    0 D !        ����������������Y   �����   H   �@  4 \ D        ����������������[   ��         �   
   <   �@  8 L D        ����������������\       
   <   �@  < L D        ����������������]      H  
   V  W  X  X  Y  Y  [  \  ]  P   p   �   �   �   �   �   �   ,      <   x   �   �   ,  h  �  �  �  <    �     L D        ����������������j      `   
   <   �      D !         ����������������j   �����   <   �    $ L D        ����������������k      `   
   <   �    ( D !        ����������������k   �����   <   �    , L D        ����������������m     �  
   <   �    0 D !        ����������������m   �����   <   �    4 L D        ����������������n     �  
   <   �    8 D !        ����������������n   �����   H   �@  < \ D        ����������������o   ��         �   
   < 	  �@  @ L D	        ����������������p       
   < 
  �@  D L D
        ����������������q      H  
   j  j  k  k  m  m  n  n  o  p  q  P   P   |  |  �  �  �  �  �   �   ,      <   x   �   �   ,  h  �  �  (  d  �  <    �     L D        ����������������~      `   
   <   �      D !         ����������������~   �����   <   �    $ L D        ����������������      `   
   <   �    ( L D        �����������������      `   
   H   �@  , \ D        �����������������   ��         �   
   <   �@  0 L D        �����������������       
   <   �@  4 L D        �����������������      H  
   ~  ~    �  �  �  �  P   P   $  <  �   �   ,      <   x   �   �   8  t  d4   V S _ V E R S I O N _ I N F O     ���       �$    �$?                        �   S t r i n g F i l e I n f o   �   0 4 0 9 0 4 B 0   L   C o m p a n y N a m e     M i c r o s o f t   C o r p o r a t i o n   h    F i l e D e s c r i p t i o n     V i s u a l   C + +   B u i l d   S y s t e m   P a c k a g e   8   F i l e V e r s i o n     7 . 0 0 . 9 4 6 6 . 2   <   I n t e r n a l N a m e   V C P r o j e c t . d l l   � /  L e g a l C o p y r i g h t   �   M i c r o s o f t   C o r p o r a t i o n .     A l l   r i g h t s   r e s e r v e d .     D   O r i g i n a l F i l e n a m e   V C P r o j e c t . d l l   \   P r o d u c t N a m e     M i c r o s o f t �   V i s u a l   S t u d i o   . N E T   <   P r o d u c t V e r s i o n   7 . 0 0 . 9 4 6 6 . 2   D    V a r F i l e I n f o     $    T r a n s l a t i o n     	�    @comp.idV ��   .debug$S       F                 .rsrc$01       t  I             .rsrc$02       �               $R000000        $R0047388G      $R006E60`n      $R007148Hq      $R007270pr      $R007298�r      $R007580�u      $R007598�u      $R007880�x      $R0079A8�y      $R0079D0�y      $R007CB8�|      $R007DE0�}      $R007E08~      $R0080F0��      $R008218�      $R008240@�      $R008528(�      $R008650P�      $R008780��      $R0087B0��      $R008A98��      $R008BC0��      $R008CF0��      $R008D20 �      $R009008�      $R0091300�      $R009260`�      $R009290��      $R009578x�      $R0096A0��      $R0096C8Ȗ      $R0099B0��      $R009AD8ؚ      $R009B00 �      $R009DE8�      $R009F10�      $R009F388�      $R00A220 �      $R00A348H�      $R00A370p�      $R00A658X�      $R00A780��      $R00A7A8��      $R00AA90��      $R00ABB8��      $R00ABE0�      $R00AEC8Ȯ      $R00AFF0�      $R00B018�      $R00B300 �      $R00B428(�      $R00B450P�      $R00B7388�      $R00B860`�      $R00B888��      $R00BB70p�      $R00BC98��      $R00BCC0��      $R00BFA8��      $R00C0D0��      $R00C0F8��      $R00C3E0��      $R00C508�      $R00C5300�      $R00C818�      $R00C940@�      $R00C968h�      $R00CC50P�      $R00CD78x�      $R00CDA0��      $R00F180��      $R010568h         