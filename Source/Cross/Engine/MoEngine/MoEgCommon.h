#ifndef __MO_EG_COMMON_H__
#define __MO_EG_COMMON_H__
//************************************************************

#ifndef __MO_EG_PUBLIC_H__
#include "MoEgPublic.h"
#endif // __MO_EG_PUBLIC_H__

#define MO_ENG_TAIL_MAXCOUNT 64

#define MO_ENG_GEOM_PI2         (MO_PI_FLOAT * 2)
#define MO_ENG_GEOM_RADIAN_RATE (180.0f / MO_PI_FLOAT)
#define MO_ENG_GEOM_DEGREE_RATE (MO_PI_FLOAT / 180.0f)

MO_NAMESPACE_BEGIN

//============================================================
// <T>�ı��С�¼���</T>
//============================================================
class SResizeEvent : public SEvent{
public:
   SIntSize2 size;
public:
   //------------------------------------------------------------
   // <T>����ı��С�¼���</T>
   SResizeEvent(TAny* pSender, TInt width, TInt heigh) : SEvent(pSender){
      size.Set(width, heigh);
   }
};
//------------------------------------------------------------
typedef MO_EG_DECLARE TListeners<SResizeEvent> TResizeListeners;

//============================================================
// <T>��Ⱦ��Ŀ��Ϣ��</T>
//============================================================
struct MO_EG_DECLARE SRenderableItem{
public:
   // ����
   SFloatPoint3 location;
   // �ߴ�
   SFloatSize3 size;
   // ��ת
   SFloatVector3 rotation;
   // ������ɫ
   SFloatColor4 groundColor;
   // ��������
   SFloatCoord coord;
   // ����
   SFloatMatrix3d matrix;
public:
   //------------------------------------------------------------
   // <T>���측������ɫ��</T>
   MO_INLINE SRenderableItem(){
   }
};
//------------------------------------------------------------
typedef MO_EG_DECLARE TFixVector<SRenderableItem, 64> SRenderableItems;

//============================================================
// <T>��Ⱦ��Ϣ��</T>
//============================================================
struct MO_EG_DECLARE SRenderable{
public:
   SRenderableItems items;
public:
   //------------------------------------------------------------
   // <T>���측������ɫ��</T>
   MO_INLINE SRenderable(){
   }
public:
   //------------------------------------------------------------
   // <T>�ռ�һ����Ŀ��</T>
   MO_INLINE SRenderableItem& Alloc(){
      TInt index = items.Count();
      items.SetCount(index + 1);
      return items.Get(index);
   }
   //------------------------------------------------------------
   // <T>����Ҫ����Ŀ��</T>
   MO_INLINE void Push(SRenderableItem& item){
      items.Push(item);
   }
};

//============================================================
// <T>�ռ䶨�塣</T>
//============================================================
struct MO_EG_DECLARE SFloatSpace{
public:
   SFloatPoint3 location;
   SFloatSize3 size;
   SFloatVector3 rotation;
   SFloatColor4 color;
public:
   //------------------------------------------------------------
   // <T>������ζ��塣</T>
   SFloatSpace(){
   }
public:
   //------------------------------------------------------------
   // <T>�������ꡣ</T>
   void SetLocation(TFloat x = 0.0f, TFloat y = 0.0f, TFloat z = 0.0f){
      location.Set(x, y, z);
   }
   //------------------------------------------------------------
   // <T>���óߴ硣</T>
   void SetSize(TFloat width = 0.0f, TFloat height = 0.0f, TFloat deep = 0.0f){
      size.Set(width, height, deep);
   }
   //------------------------------------------------------------
   // <T>������ת��</T>
   void SetRotation(TFloat x = 0.0f, TFloat y = 0.0f, TFloat z = 0.0f){
      rotation.Set(x, y, z);
   }
};
//------------------------------------------------------------
typedef MO_EG_DECLARE TFixVector<SFloatSpace, MO_ENG_TAIL_MAXCOUNT> TFloatSpaceTails;

MO_NAMESPACE_END
      
//************************************************************
#endif // __MO_EG_COMMON_H__