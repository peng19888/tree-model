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

#include "qt_awesome.hh"

#include <QtAwesome/QtAwesome.h>

#include <QApplication>

namespace editor {

  QtAwesome* fa_instance()
  {
    static QtAwesome *i = nullptr;
    if (!i) {
      i = new QtAwesome(QApplication::instance());
      // XXX should be part of the constructor ...
      i->initFontAwesome();
    }
    return i;
  }


}
