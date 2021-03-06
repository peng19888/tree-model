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

#ifndef EDITOR_COMMAND_OPEN_BER_HH
#define EDITOR_COMMAND_OPEN_BER_HH

#include <tuple>
#include <deque>
#include <string>

class QAbstractItemModel;
class QString;

namespace tree_model {
  class Base;
}

namespace editor {
  class File_Type;
  namespace command {


    std::tuple<QAbstractItemModel *, tree_model::Base*,
      std::deque<std::string> >
        open_ber(const QString &filename);

    std::tuple<QAbstractItemModel *, tree_model::Base*>
      open_ber(const QString &filename, File_Type &ft);

  }
}

#endif
