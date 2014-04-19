#include "MoCmFormat.h"
#include "MoCmLanguage.h"

MO_NAMESPACE_BEGIN

//============================================================
// <T>构造长整数字符串。</T>
//============================================================
TFsInteger64::TFsInteger64(){
   Set(0);
}

//============================================================
// <T>构造长整数字符串。</T>
//
// @param value 长整数
//============================================================
TFsInteger64::TFsInteger64(TInt64 value){
   Set(value);
}

//============================================================
// <T>构造长整数字符串。</T>
//
// @param pValue 字符串
//============================================================
TFsInteger64::TFsInteger64(TCharC* pValue){
   Parse(pValue);
}

//============================================================
// <T>构造长整数字符串。</T>
//
// @param ptr 字符串指针
//============================================================
TFsInteger64::TFsInteger64(const TStringPtrC& ptr){
   Parse(ptr.MemoryC());
}

//============================================================
// <T>构造长整数字符串。</T>
//
// @param value 长整数字符串
//============================================================
TFsInteger64::TFsInteger64(const TFsInteger64& value){
   Parse(value.MemoryC());
}

//============================================================
// <T>赋值操作。</T>
//
// @param value 长整数
//============================================================
void TFsInteger64::operator=(TInt64 value){
   Set(value);
}

//============================================================
// <T>赋值操作。</T>
//
// @param pValue 字符串
//============================================================
void TFsInteger64::operator=(TCharC* pValue){
   Parse(pValue);
}

//============================================================
// <T>赋值操作。</T>
//
// @param ptr 字符串指针
//============================================================
void TFsInteger64::operator=(const TStringPtrC& ptr){
   Parse(ptr.MemoryC());
}

//============================================================
// <T>赋值操作。</T>
//
// @param value 长整数字符串
//============================================================
void TFsInteger64::operator=(const TFsInteger64& value){
   Parse(value.MemoryC());
}

//============================================================
// <T>获得长整数内容。</T>
//
// @return 长整数
//============================================================
TInt64 TFsInteger64::Get(){
   return _value;
}

//============================================================
// <T>设置长整数内容。</T>
//
// @param value 长整数
//============================================================
void TFsInteger64::Set(TInt64 value){
   _value = value;
   RInt64::ToString(_value, _memory, _capacity);
   Fix();
}

//============================================================
// <T>从字符串解析长整数内容。</T>
//
// @return 长整数
//============================================================
TInt64 TFsInteger64::Parse(){
   return RInt::Parse(_memory);
}

//============================================================
// <T>从字符串解析长整数内容。</T>
//
// @param pValue 字符串
// @return 长整数
//============================================================
TInt64 TFsInteger64::Parse(TCharC* pValue){
   _value = RInt64::Parse(pValue);
   Assign(pValue);
   return _value;
}

//============================================================
// <T>返回字符串。</T>
//
// @return 字符串
//============================================================
TCharC* TFsInteger64::ToString(){
   return RInt64::ToString(_value, _memory, _capacity);
}

MO_NAMESPACE_END
