call "C:\Program Files (x86)\Microsoft Visual Studio 12.0\VC\bin\vcvars32.bat"

pushd Questions\%1

cl.exe /W4 /EHsc /Fo..\..\Output\ /Fe..\..\Output\ %2.cpp 

popd

pushd Output
%2.exe
popd