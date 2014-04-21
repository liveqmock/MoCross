﻿using MO.Common.Lang;
using MO.Content3d;
using MO.Content3d.Common;
using MO.Content3d.Resource.Template;
using MO.Core.Content.Catalog;
using System.Windows.Forms;

namespace MO.Design3d.Template.Controls
{
   //============================================================
   // <T>模板设计表单。</T>
   //============================================================
   public partial class QDsTemplateDesign : UserControl
   {
      //============================================================
      // <T>构造模板设计表单。</T>
      //============================================================
      public QDsTemplateDesign() {
         InitializeComponent();
      }

      //============================================================
      // <T>加载树目录。</T>
      //============================================================
      private void LoadCatalogNode(TreeNodeCollection nodes, FCfgFolder folder) {
         // 标志是否加载资源文件
         bool loaded = true;
         // 取得文件中子文件的个数
         int count = folder.Folders.Count;
         for(int n = 0; n < count; n++) {
            // 循环取得每个文件
            FDrFolder subfolder = folder.Folders[n] as FDrFolder;
            // 生成节点 
            TreeNode childNode = new TreeNode(subfolder.Label);
            childNode.Tag = subfolder;
            subfolder.TreeNode = childNode;
            // 取得路径
            string path = subfolder.ConfigFileName;
            object tag = subfolder.Tag;
            if(tag is FDrTemplate) {
               childNode.ImageKey = "Template";
               childNode.SelectedImageKey = "Template";
               loaded = false;
            } else {
               childNode.ImageKey = "Folder";
               childNode.SelectedImageKey = "Folder";
            }
            nodes.Add(childNode);
            if(loaded) {
               LoadCatalogNode(childNode.Nodes, subfolder);
            }
         }
      }

      //============================================================
      // <T>打开资源。</T>
      //============================================================
      public void SelectItem(object item) {
         if(item is FDrTemplate) {
            FDrTemplate template = item as FDrTemplate;
            qdrTemplateProperty.Dock = DockStyle.Fill;
            qdrTemplateProperty.Visible = true;
            qdrTemplateProperty.LoadTemplate(template);
         } else {
            qdrTemplateProperty.Visible = false;
         }
      }

      //============================================================
      // <T>打开资源。</T>
      //============================================================
      public void Open() {
         tvwCatalog.BeginUpdate();
         LoadCatalogNode(tvwCatalog.Nodes, RContent3dManager.TemplateConsole.Folder);
         tvwCatalog.EndUpdate();
         tvwCatalog.ExpandAll();
         SelectItem(null);
      }

      //============================================================
      // <T>选中导出。</T>
      //============================================================
      public void ExportSelected() {
         FObjects<TreeNode> nodes = tvwCatalog.FetchCheckedNodes();
         foreach (TreeNode node in nodes) {
            FCfgFolder folder = node.Tag as FCfgFolder;
            if (null != folder) {
               FDrTemplate template = folder.Tag as FDrTemplate;
               if (null != template) {
                  RContent3dManager.TemplateConsole.TaskExport(template);
               }
            }
         }
      }

      //============================================================
      // <T>按照选中保存。</T>
      //============================================================
      public void SaveSelect() {
         FObjects<TreeNode> nodes = tvwCatalog.FetchCheckedNodes();
         foreach (TreeNode node in nodes) {
            FCfgFolder folder = node.Tag as FCfgFolder;
            if (folder != null) {
               FDrTemplate template = folder.Tag as FDrTemplate;
               if (null != template) {
                  template.Store();
               }
            }
         }
      }

      //============================================================
      // <T>展开所有的树节点。</T>
      //============================================================
      private void tsbExpend_Click(object sender, System.EventArgs e) {
         TreeNodeCollection nodes = tvwCatalog.Nodes;
         foreach (TreeNode node in nodes) {
            node.ExpandAll();
         }
      }

      //============================================================
      // <T>收缩所有的树节点。</T>
      //============================================================
      private void tsbCollapse_Click(object sender, System.EventArgs e) {
         TreeNodeCollection nodes = tvwCatalog.Nodes;
         foreach (TreeNode node in nodes) {
            node.Collapse();
         }
      }

      //============================================================
      // <T>选中对象。</T>
      //============================================================
      private void tvwCatalog_AfterSelect(object sender, TreeViewEventArgs e) {
         FDrFolder folder = e.Node.Tag as FDrFolder;
         if(null != folder) {
            SelectItem(folder.Tag);
         }
      }

      //============================================================
      // <T>Check 所有的复选框</T>
      //============================================================
      private void tvwCatalog_AfterCheck(object sender, TreeViewEventArgs e) {
         TreeNode node = e.Node;
         node.Expand();
         tvwCatalog.CheckNodeChildren(node.Nodes, node.Checked);
      }
   }
}