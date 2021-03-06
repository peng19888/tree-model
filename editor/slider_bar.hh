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
#ifndef EDITOR_SLIDER_BAR_HH
#define EDITOR_SLIDER_BAR_HH

#include <QWidget>

namespace editor {

  namespace Ui {
    class Slider_Bar;
  }

  class Slider_Bar : public QWidget
  {
    Q_OBJECT

    public:
      explicit Slider_Bar(QWidget *parent = nullptr);
      ~Slider_Bar();

    public slots:
      void init(int pos, int max);

    signals:
      void jump_requested(int pos);

    private:
      Ui::Slider_Bar *ui;

      void setup_slider_machine();

    private slots:
      void jump_to_edit_line_rank();

  };


} // namespace editor
#endif // EDITOR_SLIDER_BAR_HH
