#ifndef __MO_PD11_RENDER_H__
#define __MO_PD11_RENDER_H__
//************************************************************

#ifndef __MO_PD11_COMMON_H__
#include "MoPd11Common.h"
#endif // __MO_PD11_COMMON_H__

#ifndef __MO_PD11_CORE_H__
#include "MoPd11Core.h"
#endif // __MO_PD11_CORE_H__

MO_NAMESPACE_BEGIN

//============================================================
// <T>渲染层信息。</T>
//============================================================
class MO_PD11_DECLARE FPd11RenderLayout : public FRenderLayout
{
   MO_CLASS_DECLARE_INHERITS(FPd11RenderLayout, FRenderLayout);
protected:
   TInt _count;
   MO_D3D11_INPUT_ELEMENT_DESC_ARRAY _inputElements;
   ID3D11InputLayout* _piInputLayout;
   ID3D11Buffer* _piBuffer[MO_INPUT_ELEMENT_MAXCNT];
   UINT _strides[MO_INPUT_ELEMENT_MAXCNT];
   UINT _offsets[MO_INPUT_ELEMENT_MAXCNT];
public:
   FPd11RenderLayout();
   MO_ABSTRACT ~FPd11RenderLayout();
public:
   //------------------------------------------------------------
   // <T>获得本地输入层次。</T>
   MO_INLINE ID3D11InputLayout* NativeInputLayout(){
      return _piInputLayout;
   }
   //------------------------------------------------------------
   // <T>获得总数。</T>
   MO_INLINE TInt Count(){
      return _count;
   }
   //------------------------------------------------------------
   // <T>获得数据。</T>
   MO_INLINE ID3D11Buffer** Buffer(){
      return _piBuffer;
   }
   //------------------------------------------------------------
   // <T>获得宽度。</T>
   MO_INLINE UINT* Stride(){
      return _strides;
   }
   //------------------------------------------------------------
   // <T>获得位置。</T>
   MO_INLINE UINT* Offset(){
      return _offsets;
   }
public:
   MO_OVERRIDE TResult OnSetup();
};
//------------------------------------------------------------
typedef MO_PD11_DECLARE FObjects<FPd11RenderLayout*> FPd11RenderLayoutCollection;

//============================================================
// <T>渲染顶点缓冲。</T>
//============================================================
class MO_PD11_DECLARE FPd11RenderVertexBuffer : public FRenderVertexBuffer
{
   MO_CLASS_DECLARE_INHERITS(FPd11RenderVertexBuffer, FRenderVertexBuffer);
protected:
   ID3D11Buffer* _piBuffer;
public:
   FPd11RenderVertexBuffer();
   MO_ABSTRACT ~FPd11RenderVertexBuffer();
public:
   //------------------------------------------------------------
   // <T>获得本地缓冲。</T>
   MO_INLINE ID3D11Buffer* NativeBuffer(){
      return _piBuffer;
   }
public:
   MO_OVERRIDE TResult OnSetup();
public:
   MO_OVERRIDE TResult Upload(TByteC* pData, TInt length);
public:
   MO_OVERRIDE TResult Suspend();
   MO_OVERRIDE TResult Resume();
   MO_OVERRIDE TResult Dispose();
};

//============================================================
// <T>渲染索引缓冲。</T>
//============================================================
class MO_PD11_DECLARE FPd11RenderIndexBuffer : public FRenderIndexBuffer
{
   MO_CLASS_DECLARE_INHERITS(FPd11RenderIndexBuffer, FRenderVertexBuffer);
protected:
   ID3D11Buffer* _piBuffer;
public:
   FPd11RenderIndexBuffer();
   MO_ABSTRACT ~FPd11RenderIndexBuffer();
public:
   //------------------------------------------------------------
   // <T>获得本地缓冲。</T>
   MO_INLINE ID3D11Buffer* NativeBuffer(){
      return _piBuffer;
   }
public:
   MO_OVERRIDE TResult OnSetup();
public:
   MO_OVERRIDE TResult Upload(TByteC* pMemory, TInt length);
public:
   MO_OVERRIDE TResult Suspend();
   MO_OVERRIDE TResult Resume();
   MO_OVERRIDE TResult Dispose();
};

//============================================================
// <T>渲染器缓冲。</T>
//============================================================
class MO_PD11_DECLARE FPd11RenderShaderBuffer : public FRenderProgramBuffer
{
   MO_CLASS_DECLARE_INHERITS(FPd11RenderShaderBuffer, FRenderProgramBuffer);
protected:
   ID3D11Buffer* _piBuffer;
public:
   FPd11RenderShaderBuffer();
   MO_ABSTRACT ~FPd11RenderShaderBuffer();
public:
   //------------------------------------------------------------
   // <T>获得本地缓冲。</T>
   MO_INLINE ID3D11Buffer* NativeiBuffer(){
      return _piBuffer;
   }
   //------------------------------------------------------------
   // <T>设置本地缓冲。</T>
   MO_INLINE void SetNativeiBuffer(ID3D11Buffer* piBuffer){
      _piBuffer = piBuffer;
   }
public:
   MO_OVERRIDE TResult OnSetup();
public:
   MO_OVERRIDE TResult Commit();
   MO_OVERRIDE TResult Bind();
};

//============================================================
// <T>渲染器参数。</T>
//============================================================
class MO_PD11_DECLARE FPd11RenderShaderParameter : public FRenderProgramParameter
{
   MO_CLASS_DECLARE_INHERITS(FPd11RenderShaderParameter, FRenderProgramParameter);
protected:
   ID3D11ShaderReflectionVariable* _piVariable;
public:
   FPd11RenderShaderParameter();
   MO_ABSTRACT ~FPd11RenderShaderParameter();
public:
   //------------------------------------------------------------
   // <T>设置缓冲。</T>
   MO_INLINE void NativeVariable(FPd11RenderShaderBuffer* pBuffer){
      _buffer = pBuffer;
   }
   //------------------------------------------------------------
   // <T>获得本地变量。</T>
   MO_INLINE ID3D11ShaderReflectionVariable* NativeVariable(){
      return _piVariable;
   }
public:
   TResult LinkNative(ID3D11ShaderReflectionVariable* piVariable);
};

//============================================================
// <T>顶点渲染器。</T>
//============================================================
class MO_PD11_DECLARE FPd11RenderVertexShader : public FRenderVertexShader
{
   MO_CLASS_DECLARE_INHERITS(FPd11RenderVertexShader, FRenderVertexShader);
protected:
   ID3D10Blob* _piData;
   ID3D11ClassLinkage* _piLinkage;
   ID3D11VertexShader* _piShader;
public:
   FPd11RenderVertexShader();
   MO_ABSTRACT ~FPd11RenderVertexShader();
public:
   //------------------------------------------------------------
   // <T>获得本地数据。</T>
   MO_INLINE ID3D10Blob* NativeData(){
      return _piData;
   }
   //------------------------------------------------------------
   // <T>获得本地渲染器。</T>
   MO_INLINE ID3D11VertexShader* NativeShader(){
      return _piShader;
   }
public:
   MO_OVERRIDE TResult Setup();
public:
   MO_OVERRIDE TResult Compile(TCharC* pSource);
public:
   MO_OVERRIDE TResult Suspend();
   MO_OVERRIDE TResult Resume();
   MO_OVERRIDE TResult Dispose();
};

//============================================================
// <T>像素渲染器。</T>
//============================================================
class MO_PD11_DECLARE FPd11RenderFragmentShader : public FRenderFragmentShader
{
   MO_CLASS_DECLARE_INHERITS(FPd11RenderFragmentShader, FRenderFragmentShader);
protected:
   ID3D10Blob* _piData;
   ID3D11PixelShader* _piShader;
public:
   FPd11RenderFragmentShader();
   MO_ABSTRACT ~FPd11RenderFragmentShader();
public:
   //------------------------------------------------------------
   // <T>获得本地数据。</T>
   MO_INLINE ID3D10Blob* NativeData(){
      return _piData;
   }
   //------------------------------------------------------------
   // <T>获得本地渲染器。</T>
   MO_INLINE ID3D11PixelShader* NativeShader(){
      return _piShader;
   }
public:
   MO_OVERRIDE TResult Setup();
public:
   MO_OVERRIDE TResult Compile(TCharC* pSource);
public:
   MO_OVERRIDE TResult Suspend();
   MO_OVERRIDE TResult Resume();
   MO_OVERRIDE TResult Dispose();
};

//============================================================
// <T>渲染程序。</T>
//============================================================
class MO_PD11_DECLARE FPd11RenderProgram : public FRenderProgram
{
   MO_CLASS_DECLARE_INHERITS(FPd11RenderProgram, FRenderProgram);
protected:
   ID3D11InputLayout* _piInputLayout;
   MO_D3D11_INPUT_ELEMENT_DESC_ARRAY inputElements;
public:
   FPd11RenderProgram();
   MO_ABSTRACT ~FPd11RenderProgram();
public:
   //------------------------------------------------------------
   // <T>获得本地输入层次。</T>
   MO_INLINE ID3D11InputLayout* NativeInputLayout(){
      return _piInputLayout;
   }
public:
   MO_OVERRIDE TInt FindDefine(TCharC* pCode);
   MO_OVERRIDE TInt FindAttribute(TCharC* pCode);
   MO_OVERRIDE TResult BindAttribute(TInt slot, TCharC* pCode);
protected:
   TResult BuildShader(FRenderShader* pShader, ID3D10Blob* piData);
public:
   MO_OVERRIDE TResult Setup();
   MO_OVERRIDE TResult Build();
   MO_OVERRIDE TResult Link();
public:
   MO_OVERRIDE TResult Suspend();
   MO_OVERRIDE TResult Resume();
   MO_OVERRIDE TResult Dispose();
};

//============================================================
// <T>渲染目标。</T>
//============================================================
class MO_PD11_DECLARE FPd11RenderTarget : public FRenderTarget
{
   MO_CLASS_DECLARE_INHERITS(FPd11RenderTarget, FRenderTarget);
protected:
   ID3D11RenderTargetView* _piRenderTarget;
   ID3D11DepthStencilView* _piDepthStencil;
public:
   FPd11RenderTarget();
   MO_ABSTRACT ~FPd11RenderTarget();
public:
   //------------------------------------------------------------
   // <T>获得本地渲染目标。</T>
   MO_INLINE ID3D11RenderTargetView* NativeRenderTarget(){
      return _piRenderTarget;
   }
   //------------------------------------------------------------
   // <T>设置本地渲染目标。</T>
   MO_INLINE void SetNativeRenderTarget(ID3D11RenderTargetView* piRenderTarget){
      _piRenderTarget = piRenderTarget;
   }
   //------------------------------------------------------------
   // <T>获得本地深度缓冲。</T>
   MO_INLINE ID3D11DepthStencilView* NativeDepthStencil(){
      return _piDepthStencil;
   }
   //------------------------------------------------------------
   // <T>设置本地深度缓冲。</T>
   MO_INLINE void SetNativeDepthStencil(ID3D11DepthStencilView* piDepthStencil){
      _piDepthStencil = piDepthStencil;
   }
public:
   MO_OVERRIDE TResult OnSetup();
public:
   MO_OVERRIDE TResult Suspend();
   MO_OVERRIDE TResult Resume();
   MO_OVERRIDE TResult Dispose();
};

//============================================================
// <T>渲染平面纹理。</T>
//============================================================
class MO_PD11_DECLARE FPd11RenderFlatTexture : public FRenderFlatTexture
{
   MO_CLASS_DECLARE_INHERITS(FPd11RenderFlatTexture, FRenderFlatTexture);
protected:
   ID3D11Texture2D* _piTexture;
   ID3D11ShaderResourceView* _piView;
   ID3D11SamplerState* _piState;
public:
   FPd11RenderFlatTexture();
   MO_ABSTRACT ~FPd11RenderFlatTexture();
public:
   //------------------------------------------------------------
   // <T>获得本地纹理。</T>
   MO_INLINE ID3D11Texture2D* NativeTexture(){
      return _piTexture;
   }
   //------------------------------------------------------------
   // <T>获得本地视图。</T>
   MO_INLINE ID3D11ShaderResourceView* NativeView(){
      return _piView;
   }
   //------------------------------------------------------------
   // <T>获得取样器状态。</T>
   MO_INLINE ID3D11SamplerState* NativeState(){
      return _piState;
   }
public:
   MO_OVERRIDE TResult OnSetup();
public:
   MO_OVERRIDE TResult Resize(TInt width, TInt height);
   MO_OVERRIDE TResult Unserialize(IDataInput* pInput);
   MO_OVERRIDE TResult Upload(TByteC* pData, TInt length);
   TResult LoadDataFile(TCharC* pFileName);
public:
   MO_OVERRIDE TResult Suspend();
   MO_OVERRIDE TResult Resume();
   MO_OVERRIDE TResult Dispose();
};

//============================================================
// <T>渲染CUBE纹理。</T>
//============================================================
class MO_PD11_DECLARE FPd11RenderCubeTexture : public FRenderCubeTexture
{
   MO_CLASS_DECLARE_INHERITS(FPd11RenderCubeTexture, FRenderFlatTexture);
protected:
   ID3D11Texture2D* _piTexture;
   ID3D11ShaderResourceView* _piView;
   ID3D11SamplerState* _piState;
public:
   FPd11RenderCubeTexture();
   MO_ABSTRACT ~FPd11RenderCubeTexture();
public:
   //------------------------------------------------------------
   // <T>获得本地纹理。</T>
   MO_INLINE ID3D11Texture2D* NativeTexture(){
      return _piTexture;
   }
   //------------------------------------------------------------
   // <T>获得本地视图。</T>
   MO_INLINE ID3D11ShaderResourceView* NativeView(){
      return _piView;
   }
   //------------------------------------------------------------
   // <T>获得取样器状态。</T>
   MO_INLINE ID3D11SamplerState* NativeState(){
      return _piState;
   }
public:
   MO_OVERRIDE TResult OnSetup();
public:
   MO_OVERRIDE TResult Resize(TInt size);
   MO_OVERRIDE TResult Unserialize(IDataInput* pInput);
   MO_OVERRIDE TResult Upload(TByteC* pData, TInt length);
   TResult LoadDataFile(TCharC* pFileName);
public:
   MO_OVERRIDE TResult Suspend();
   MO_OVERRIDE TResult Resume();
   MO_OVERRIDE TResult Dispose();
};

//============================================================
// <T>渲染设备。</T>
//============================================================
class MO_PD11_DECLARE FPd11RenderDevice : public FPdxRenderDevice
{
   MO_CLASS_DECLARE_INHERITS(FPd11RenderDevice, FPdxRenderDevice);
protected:
   D3D_DRIVER_TYPE _driverType;
   D3D_FEATURE_LEVEL _featureLevel;
   // 纹理信息
   TBool _optionTexture;
   // 关联顶点缓冲集合
   FRenderFlatTextureList* _pLinkFlatTextures;
   FRenderCubeTextureList* _pLinkCubeTextures;
   // 接口指针
   IDXGISwapChain* _piSwapChain;
   ID3D11Device* _piDevice;
   ID3D11DeviceContext* _piContext;
   GPtr<FPd11RenderTarget> _defaultRenderTarget;
   ID3D11RasterizerState* _piRasterizerState;
   ID3D11BlendState* _piBlendEnableState;
   ID3D11BlendState* _piBlendDisableState;
public:
   FPd11RenderDevice();
   MO_ABSTRACT ~FPd11RenderDevice();
protected:
   TBool UpdateContext();
public:
   //------------------------------------------------------------
   // <T>获得本地交换链。</T>
   MO_INLINE IDXGISwapChain* NativeSwapChain(){
      return _piSwapChain;
   }
   //------------------------------------------------------------
   // <T>获得本地设备。</T>
   MO_INLINE ID3D11Device* NativeDevice(){
      return _piDevice;
   }
   //------------------------------------------------------------
   // <T>获得本地环境。</T>
   MO_INLINE ID3D11DeviceContext* NativeContext(){
      return _piContext;
   }
public:
   MO_OVERRIDE TResult Setup();
   MO_ABSTRACT TResult Suspend();
   MO_ABSTRACT TResult Resume();
public:
   MO_OVERRIDE TResult CheckError(TCharC* pCode, TCharC* pMessage, ...);
public:
   MO_OVERRIDE FRenderVertexBuffer* CreateVertexBuffer(FClass* pClass = NULL);
   MO_OVERRIDE FRenderIndexBuffer* CreateIndexBuffer(FClass* pClass = NULL);
   MO_OVERRIDE FRenderProgram* CreateProgrom(FClass* pClass = NULL);
   MO_OVERRIDE FRenderTarget* CreateRenderTarget(FClass* pClass = NULL);
   MO_OVERRIDE FRenderFlatTexture* CreateFlatTexture(FClass* pClass = NULL);
   MO_OVERRIDE FRenderCubeTexture* CreateCubeTexture(FClass* pClass = NULL);
public:
   MO_OVERRIDE TResult Clear(TFloat red = 0.0f, TFloat green = 0.0f, TFloat blue = 0.0f, TFloat alpha = 1.0f, TFloat depth = 1.0f);
   MO_OVERRIDE TResult SetBackBuffer(TInt width, TInt height, TInt antiAlias, TBool depthed = ETrue);
   MO_OVERRIDE TResult SetFillMode(ERenderFillMode fillModeCd);
   MO_OVERRIDE TResult SetDepthMode(TBool depth, ERenderDepthMode depthCd = ERenderDepthMode_None);
   MO_OVERRIDE TResult SetCullingMode(TBool cull, ERenderCullMode cullCd = ERenderCullMode_None);
   MO_OVERRIDE TResult SetBlendFactors(TBool blend, ERenderBlendMode sourceCd = ERenderBlendMode_None, ERenderBlendMode targetCd = ERenderBlendMode_None);
   MO_OVERRIDE TResult SetScissorRectangle(TInt left, TInt top, TInt width, TInt height);
   MO_OVERRIDE TResult SetRenderTarget(FRenderTarget* pRenderTarget = NULL);
   MO_OVERRIDE TResult SetProgram(FRenderProgram* pProgram);
   MO_OVERRIDE TResult SetLayout(FRenderProgramLayout* pLayout);
   MO_OVERRIDE TResult BindConstData(ERenderShader shaderCd, TInt slot, ERenderParameterFormat formatCd, TAnyC* pData, TInt length);
   MO_OVERRIDE TResult BindConstFloat3(ERenderShader shaderCd, TInt slot, TFloat x = 0.0f, TFloat y = 0.0f, TFloat z = 0.0f);
   MO_OVERRIDE TResult BindConstFloat4(ERenderShader shaderCd, TInt slot, TFloat x = 0.0f, TFloat y = 0.0f, TFloat z = 0.0f, TFloat w = 1.0f);
   MO_OVERRIDE TResult BindConstMatrix3x3(ERenderShader shaderCd, TInt slot, const SFloatMatrix3d& matrix);
   MO_OVERRIDE TResult BindConstMatrix4x4(ERenderShader shaderCd, TInt slot, const SFloatMatrix3d& matrix);
   MO_OVERRIDE TResult BindShaderBuffer(FRenderProgramBuffer* pBuffer);
   MO_OVERRIDE TResult BindVertexBuffer(TInt slot, FRenderVertexBuffer* pVertexBuffer, TInt offset, ERenderAttributeFormat formatCd);
   MO_OVERRIDE TResult BindTexture(TInt slot, FRenderTexture* pTexture);
   MO_OVERRIDE TResult DrawTriangles(FRenderIndexBuffer* pIndexBuffer, TInt offset, TInt count);
   MO_OVERRIDE TResult Present();
};

MO_NAMESPACE_END

//************************************************************
#endif // __MO_PD11_RENDER_H__
