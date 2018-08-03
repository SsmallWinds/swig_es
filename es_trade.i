%module(directors="1") es_trade

%include "typemaps.i"

%{
#include "EsForeignApiType.h"
#include "EsForeignApiErrCode.h"
#include "EsForeignApiStruct.h"
#include "EsunnyForeignApi.h"

using namespace ESForeign;
%}

%{
static inline void printException(JNIEnv * jenv, jthrowable throwable){
    if (throwable) {
        jclass throwclz = jenv->FindClass("java/lang/Throwable");
        if (throwclz) {
            jmethodID printStackMethod = jenv->GetMethodID(throwclz, "printStackTrace", "()V");
            if (printStackMethod) {
                jenv->CallNonvirtualVoidMethod(throwable, throwclz, printStackMethod);
            }
        }
    }
}
%}
%feature("director:except") %{
    jthrowable $error = jenv->ExceptionOccurred();
    if ($error) {
        jenv->ExceptionClear();
        printException(jenv, $error);
        throw Swig::DirectorException(jenv, $error);
    }
%}

%include "various.i"



%javaconst(1);

%include "EsForeignApiType.h"
%include "EsForeignApiErrCode.h"
%include "EsForeignApiStruct.h"


%feature("director") IEsunnyTradeSpi;
%include "EsunnyForeignApi.h"




%include "cpointer.i"
%pointer_functions(int,intp);
%pointer_functions(unsigned int,unsignedintp);


