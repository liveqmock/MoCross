﻿using MO.Common.Lang.Reflection;
namespace MO.Common.Lang
{
   //============================================================
   // <T>单件管理器。</T>
   //============================================================
   public class RSingleton<T>
   {
      // 单件对象
      protected static T _instance;

      //============================================================
      // <T>获取单件管理器。</T>
      //============================================================
      public static T Instance {
         get { return _instance; }
      }

      //============================================================
      // <T>创建单件管理器。</T>
      //============================================================
      public static void Create() {
         _instance = RClass.CreateInstance<T>();
      }

      //============================================================
      // <T>释放单件管理器。</T>
      //============================================================
      public static void Destory() {
      }
   }
}