#include "MoPd10Render.h"

MO_NAMESPACE_BEGIN

MO_CLASS_IMPLEMENT_INHERITS(FPd10RenderShaderParameter, FRenderShaderParameter);

//============================================================
// <T>������Ⱦ��������</T>
//============================================================
FPd10RenderShaderParameter::FPd10RenderShaderParameter(){
   MO_CLEAR(_piVariable);
}

//============================================================
// <T>������Ⱦ��������</T>
//============================================================
FPd10RenderShaderParameter::~FPd10RenderShaderParameter(){
}

//============================================================
// <T>����������Ϣ��</T>
//
// @param piVariable �����ӿ�
// @return �������
//============================================================
TResult FPd10RenderShaderParameter::LinkNative(ID3D10ShaderReflectionVariable* piVariable){
   // �������
   D3D10_SHADER_VARIABLE_DESC descriptor;
   HRESULT dxResult = piVariable->GetDesc(&descriptor);
   if(FAILED(dxResult)){
      MO_FATAL("Get variable description failure.");
      return EFailure;
   }
   // ��������
   _name = descriptor.Name;
   // �ж��Ƿ��Ǳ�ʹ��
   if((descriptor.uFlags & D3D_SVF_USED) == D3D_SVF_USED){
      _statusUsed = ETrue;
   }
   // ��������
   _slot = descriptor.StartOffset;
   _size = descriptor.Size;
   return ESuccess;
}

MO_NAMESPACE_END