add_library(model STATIC
  bundle.h
  clipboard.h
  fragment.h
  fragmentgroup.h
  model.h
  atom.cpp 
  bond.cpp 
  build.cpp 
  bundle.cpp
  cell.cpp 
  clipboard.cpp
  component.cpp
  energy.cpp 
  expression.cpp 
  fragment.cpp
  fragmentgroup.cpp
  glyph.cpp
  grid.cpp
  icon.cpp
  labels.cpp
  log.cpp
  measure.cpp 
  model.cpp 
  modelextras.cpp 
  molecule.cpp 
  pattern.cpp 
  render.cpp
  select.cpp 
  selection.cpp
  site.cpp 
  trajectory.cpp 
  transform.cpp 
  typing.cpp 
  undo.cpp 
  view.cpp
  zmatrix.cpp
)
target_include_directories(model PRIVATE
  ${PROJECT_SOURCE_DIR}/src
  ${Qt5Gui_INCLUDE_DIRS}
)
target_link_libraries(model render)

