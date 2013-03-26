@ECHO OFF
"C:\Program Files\WiX Toolset v3.7\bin\candle.exe" "FLAC frontend.wxs"
"C:\Program Files\WiX Toolset v3.7\bin\light.exe" -ext WixUIExtension -ext WixNetFxExtension "FLAC frontend.wixobj"
PAUSE