// Copyright 2016, Georg Sauthoff <mail@georg.so>

/* {{{ LGPLv3

    This file is part of tree-model.

    tree-model is free software: you can redistribute it and/or modify
    it under the terms of the GNU Lesser General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    tree-model is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public License
    along with tree-model.  If not, see <http://www.gnu.org/licenses/>.

}}} */
#ifndef EDITOR_TREE_VIEW_HH
#define EDITOR_TREE_VIEW_HH

#include <QTreeView>
class QAction;

namespace grammar {
  class Grammar;
}
namespace editor {
  class File_Type;

  class Tree_View : public QTreeView
  {
    Q_OBJECT
    public:
      Tree_View(QWidget *parent = nullptr);

      void contextMenuEvent(QContextMenuEvent *event) override;
      void keyPressEvent(QKeyEvent *event) override;

      void set_remove_action(QAction *a);
      void set_edit_action(QAction *a);
      void set_add_child_action(QAction *a);
      void set_add_sibling_action(QAction *a);
      void set_cut_action(QAction *a);
      void set_copy_action(QAction *a);
      void set_paste_action(QAction *a);
      void set_paste_as_child_action(QAction *a);

      void breadth_first_expand(unsigned n);
      void breadth_first_collapse(unsigned n);

    signals:
      void remove_triggered(const QModelIndexList &selected_indexes);
      void edit_triggered  (const QModelIndex &);
      void add_child_triggered  (const QModelIndex &);
      void add_sibling_triggered(const QModelIndex &);
      void cut_triggered(const QModelIndexList &selected_indexes);
      void copy_triggered(const QModelIndexList &selected_indexes);
      void paste_triggered(const QModelIndexList &selected_indexes);
      void paste_as_child_triggered(const QModelIndexList &selected_indexes);

      void selection_model_changed(const QItemSelectionModel *smodel);
      void selection_changed(const QItemSelection &selected,
          const QItemSelection &deselected);
      void something_selected(bool b);

      void current_changed(const QModelIndex &current,
          const QModelIndex &previous);

    public slots:
      void set_model(QAbstractItemModel *model);
      void apply_grammar(const grammar::Grammar *g);
      void apply_file_type(const File_Type &ft);

    private slots:
      void trigger_edit();
      void trigger_add_child();
      void trigger_add_sibling();
      void trigger_remove();
      void trigger_cut();
      void trigger_copy();
      void trigger_paste();
      void trigger_paste_as_child();

    protected slots:
      void selectionChanged(const QItemSelection &selected,
          const QItemSelection &deselected) override;
      void currentChanged(const QModelIndex &current,
          const QModelIndex &previous) override;

    private:
      QModelIndex context_index_;
      QAction *add_child_action_   {nullptr};
      QAction *add_sibling_action_ {nullptr};
      QAction *edit_action_        {nullptr};
      QAction *remove_action_      {nullptr};
      QAction *cut_action_         {nullptr};
      QAction *copy_action_        {nullptr};
      QAction *paste_action_       {nullptr};
      QAction *paste_as_child_action_{nullptr};
      bool context_menu_visible_   {false};

      QModelIndex index_for_update();
  };

} // namespace editor

#endif // EDITOR_TREE_VIEW_HH
