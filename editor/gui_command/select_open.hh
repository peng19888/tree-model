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
#ifndef EDITOR_GUI_COMMAND_SELECT_OPEN_HH
#define EDITOR_GUI_COMMAND_SELECT_OPEN_HH

#include <QObject>

#include <editor/gui_command/open.hh>

class QAbstractItemModel;
class QString;
class QWidget;

namespace editor {
  namespace gui_command {

    class Open;

    class Select_Open : public Open
    {
      Q_OBJECT
      public:
        explicit Select_Open(QWidget *parent = nullptr);

      public slots:
        void open();

    };

  } // namespace command
} // namespace editor


#endif
