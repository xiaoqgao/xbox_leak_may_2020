rebase -b 0x70000000 -d -v -R %JazzDir% -G %JazzDir%\DebugRebase.txt "%JazzDir%\Band Editor\Debug\BandEditor.ocx" %JazzDir%\Band Editor\Grid\Debug\PanVol.ocx" "%JazzDir\Style Designer\Debug\StyleDesigner.ocx" -G %JazzDir%\XboxDebugRebase.txt "%JazzDir%\Band Editor\Xbox_Debug\BandEditor.ocx"
rebase -b 0x70000000 -d -v -R %JazzDir% -G %JazzDir%\ReleaseRebase.txt "%JazzDir%\Band Editor\Release\BandEditor.ocx" "%JazzDir%\Band Editor\Grid\Release\PanVol.ocx" "%JazzDir%\Style Designer\Release\StyleDesigner.ocx" -G %JazzDir%\XboxReleaseRebase.txt "%JazzDir%\Band Editor\Xbox_Release\BandEditor.ocx"
