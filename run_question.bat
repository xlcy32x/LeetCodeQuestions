call "C:\Program Files (x86)\Microsoft Visual Studio 12.0\VC\bin\vcvars32.bat"

pushd Questions

cl /W4 /EHsc /Fo..\Output\ /Fe..\Output\ %1.cpp 

popd

pushd Output
%1.exe > %1.txt 
popd