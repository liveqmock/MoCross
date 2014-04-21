﻿using System;

namespace MO.Core.Logic.Task
{
   //============================================================
   // <T>任务接口。<T>
   //============================================================
   public interface ITask
   {
      //============================================================
      // <T>获得标签。<T>
      //============================================================
      string Label { get; }

      //============================================================
      // <T>获得或设置开始时间。<T>
      //============================================================
      DateTime StartDateTime { get; }

      //============================================================
      // <T>获得或设置结束时间。<T>
      //============================================================
      DateTime EndDateTime { get; }

      //============================================================
      // <T>获得或设置附带对象。<T>
      //============================================================
      object Tag { get; set; }

      //============================================================
      // <T>开始处理事件 <T>
      //============================================================
      void OnBegin();

      //============================================================
      // <T>处理中回调事件。<T>
      //============================================================      
      void OnProcess();

      //============================================================
      // <T>结束处理事件 <T>
      //============================================================      
      void OnEnd();
   }
}