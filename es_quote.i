%module(directors="1") es_quote

%include "typemaps.i"

%{
#include "TapAPICommDef.h"
#include "TapAPIError.h"
#include "TapQuoteAPIDataType.h"
#include "TapQuoteAPI.h"
%}

%include "various.i"

%javaconst(1);

%include "TapAPICommDef.h"
%include "TapAPIError.h"
%include "TapQuoteAPIDataType.h"


%feature("director") ITapQuoteAPINotify;
%include "TapQuoteAPI.h"

%include "cpointer.i"
%pointer_functions(int,intp);
%pointer_functions(unsigned int,unsignedintp);
