OBJ = main.o mainwindow.o pilamatrici.o starter.o coltura.o
MOC = coltura_moc.cpp starter_moc.cpp popup_moc.cpp mainwindow_moc.cpp
MOCOBJ = coltura_moc.o starter_moc.o popup_moc.o mainwindow_moc.o
QTLIBS = `pkg-config --libs QtGui`
QTFLAG = `pkg-config --cflags QtGui`
        
CXXFLAGS = $(QTFLAG)
LDFLAGS = $(QTLIBS)
        
colturabatterica : $(OBJ) $(MOCOBJ)
	g++ -Wall -export-dynamic -o colturabatterica $(OBJ) $(MOCOBJ) $(LDFLAGS)

main.o : main.cpp mainwindow.h pilamatrici.h coltura.h mainwindow.h starter.h main.h popup.h

mainwindow.o : mainwindow.cpp main.h mainwindow.h coltura.h

pilamatrici.o : pilamatrici.cpp pilamatrici.h main.h

starter.o : starter.cpp starter.h main.h mainwindow.h

coltura.o : coltura.cpp coltura.h main.h pilamatrici.h

popup.o : popup.cpp popup.h

#moc.o
mainwindow_moc.o : mainwindow_moc.cpp main.h mainwindow.h coltura.h

starter_moc.o : starter_moc.cpp starter.h main.h

coltura_moc.o : coltura_moc.cpp main.h coltura.h pilamatrici.h

popup_moc.o : popup_moc.cpp popup.h

#moc.cpp
mainwindow_moc.cpp : mainwindow.cpp mainwindow.h
	moc mainwindow.h -o mainwindow_moc.cpp
	
starter_moc.cpp : starter.cpp starter.h
	moc starter.h -o starter_moc.cpp
	
coltura_moc.cpp : coltura.cpp coltura.h
	moc coltura.h -o coltura_moc.cpp
	
popup_moc.cpp : popup.cpp popup.h
	moc popup.h -o popup_moc.cpp

.PHONY : clean doc
clean : 
	rm -f colturabatterica $(OBJ) $(MOC) $(MOCOBJ)
	
doc :
	doxygen Doxyfile
	
	