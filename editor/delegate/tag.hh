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

#ifndef EDITOR_DELEGATE_TAG_HH
#define EDITOR_DELEGATE_TAG_HH

#include <QStyledItemDelegate>
#include <QStringList>

namespace grammar {
  class Grammar;
}
class QAbstractItemModel;

namespace editor {
  namespace delegate {

    class Tag : public QStyledItemDelegate {
      Q_OBJECT
      public:

        using QStyledItemDelegate::QStyledItemDelegate;


        QWidget *createEditor(QWidget *parent,
            const QStyleOptionViewItem &option, const QModelIndex &index)
          const override;
      public slots:
        void apply_grammar(const grammar::Grammar *g);

      private:
        QStringList names_;
        QAbstractItemModel *names_model_ {nullptr};
        
    };

  } // delegate
} //editor

#endif // EDITOR_DELEGATE_TAG_HH
