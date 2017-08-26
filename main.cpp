#include <iostream>

using namespace std;

//asigna valores iniciales del tablero
void tableroInit(char cMat[5][5], int iTamRen, int iTamCol,
                 char cP1, char cP2, char cVacant)
{
    for (int iContRen = 0; iContRen < iTamRen; iContRen++)
    {
        for (int iContCol = 0; iContCol < iTamCol; iContCol++)
        {
            cMat[iContRen][iContCol] = cVacant;
        }
    }
    // asigna valores iniciales a las esquinas
    cMat[0][0] = cP1;
    cMat[0][iTamCol - 1] = cP1;
    cMat[iTamRen - 1][0] = cP2;
    cMat[iTamRen - 1][iTamCol - 1] = cP2;
}

// Muestra tablero
void muestraTablero(char cMat[5][5], int iTamRen, int iTamCol)
{
    int iContGuiaV = 0;
    cout << "\t";
    for (int iContGuiaH = 0; iContGuiaH < iTamCol; iContGuiaH++)
    {
        cout << iContGuiaH << "\t";
    }
    cout << endl << endl;
    for (int iContRen = 0; iContRen < iTamRen; iContRen++, iContGuiaV++)
    {
        cout << iContGuiaV << "\t";
        for (int iContCol = 0; iContCol < iTamCol; iContCol++)
        {

            cout << cMat[iContRen][iContCol] << "\t";
        }
        cout << endl << endl;
    }
    cout << endl;
}

// muestra de quien es turno de mover
void mostrarTurno(char cTurn, char cP1, char cP2)
{
    if (cTurn == cP1)
    {
        cout << "Es turno del jugador 1 " << cP1 << endl;
    }
    else
    {
        cout << "Es turno del jugador 2 " << cP2 << endl;
    }
}

// pide ubicación del blob que quiere seleccionar y valida
void preguntaCasilla(char cMat[5][5], int iTamRen, int iTamCol,
                     int &iRenBlob, int &iColBlob, char cTurn)
{
    do
    {
        do
        {
            cout << "Renglon -> ";
            cin >> iRenBlob;
        } while (iRenBlob >= iTamRen || iRenBlob < 0);
        do
        {
            cout << "Columna -> ";
            cin >> iColBlob;
        } while (iColBlob >= iTamCol || iColBlob < 0);
    } while (cMat[iRenBlob][iColBlob] != cTurn);
}

//pide direccion de movimiento
void  preguntaDireccion(char &cMov)
{
    bool bIsCorrect = false;
    cout << "a - izq" << "\t" << "x - aba" <<
    "\t" << "w - arr" << "\t" << "d - der" <<
    endl << "q - arr izq" << "\t" << "e - arr der" <<
    endl << "z - aba izq" << "\t" << "c - aba der" << endl;
    do
    {
        cin >> cMov;
        cMov = tolower(cMov);
        switch(cMov)
        {
            case 'q':
                bIsCorrect = true;
                break;
            case 'w':
                bIsCorrect = true;
                break;
            case 'e':
                bIsCorrect = true;
                break;
            case 'd':
                bIsCorrect = true;
                break;
            case 'c':
                bIsCorrect = true;
                break;
            case 'x':
                bIsCorrect = true;
                break;
            case 'z':
                bIsCorrect = true;
                break;
            case 'a':
                bIsCorrect = true;
                break;
            default:
                break;
        }
    } while (bIsCorrect == false);
    cout << endl;
}

// almacena tipos de movimiento en un arreglo
void asignaMov(int iRenBlob, int iColBlob, int &iMovArr,
               int &iMovAba, int &iMovDer, int &iMovIzq)
{
    iMovArr = iRenBlob - 1;  // arriba;
    iMovAba = iRenBlob + 1;  // abajo
    iMovIzq = iColBlob - 1;  // izquierda
    iMovDer = iColBlob + 1;  // derecha
}

// hace movimiento y transforma celdas adyacentes
int hacerMov(char cMat[5][5], char cMov, int iRenBlob, int iColBlob,
              int iTamRen,int iTamCol, char cTurn, char cTurnOpp,
              int iMovArr,  int iMovAba, int iMovDer, int iMovIzq)
{
    int iRenNew = iRenBlob;
    int iColNew = iColBlob; //nueva localizacion de blob

        switch(cMov)
        {
            case 'q':
                iRenNew = iMovArr;
                iColNew = iMovIzq;
                if (cMat[iRenNew][iColNew] != cTurnOpp)
                    cMat[iRenNew][iColNew] = cMat[iRenBlob][iColBlob];
                break;
            case 'w':
                iRenNew = iMovArr;
                if (cMat[iRenNew][iColNew] != cTurnOpp)
                    cMat[iRenNew][iColNew] = cMat[iRenBlob][iColBlob];
                break;
            case 'e':
                iRenNew = iMovArr;
                iColNew = iMovDer;
                if (cMat[iRenNew][iColNew] != cTurnOpp)
                    cMat[iRenNew][iColNew] = cMat[iRenBlob][iColBlob];
                break;
            case 'd':
                iColNew = iMovDer;
                if (cMat[iRenNew][iColNew] != cTurnOpp)
                    cMat[iRenNew][iColNew] = cMat[iRenBlob][iColBlob];
                break;
            case 'c':
                iRenNew = iMovAba;
                iColNew = iMovDer;
                if (cMat[iRenNew][iColNew] != cTurnOpp)
                    cMat[iRenNew][iColNew] = cMat[iRenBlob][iColBlob];
                break;
            case 'x':
                iRenNew = iMovAba;
                if (cMat[iRenNew][iColNew] != cTurnOpp)
                    cMat[iRenNew][iColNew] = cMat[iRenBlob][iColBlob];
                break;
            case 'z':
                iRenNew = iMovAba;
                iColNew = iMovIzq;
                if (cMat[iRenNew][iColNew] != cTurnOpp)
                    cMat[iRenNew][iColNew] = cMat[iRenBlob][iColBlob];
                break;
            case 'a':
                iColNew = iMovIzq;
                if (cMat[iRenNew][iColNew] != cTurnOpp)
                    cMat[iRenNew][iColNew] = cMat[iRenBlob][iColBlob];
                break;
            default:
                break;
        }
        asignaMov(iRenNew, iColNew, iMovArr, iMovAba, iMovDer, iMovIzq);
        // Checa cada movimiento a partir de la nueva casilla y transforma
        // los blobs del oponente a tuyos
        if (cMat[iMovArr][iMovIzq] == cTurnOpp) // Q
            cMat[iMovArr][iMovIzq] = cTurn;
        if (cMat[iMovArr][iColNew] == cTurnOpp) // W
            cMat[iMovArr][iColNew] = cTurn;
        if (cMat[iMovArr][iMovDer] == cTurnOpp) // E
            cMat[iMovArr][iMovDer] = cTurn;
        if (cMat[iRenNew][iMovDer] == cTurnOpp) // D
            cMat[iRenNew][iMovDer] = cTurn;
        if (cMat[iMovAba][iMovDer] == cTurnOpp) // C
            cMat[iMovAba][iMovDer] = cTurn;
        if (cMat[iMovAba][iColNew] == cTurnOpp) // X
            cMat[iMovAba][iColNew] = cTurn;
        if (cMat[iMovAba][iMovIzq] == cTurnOpp) // Z
            cMat[iMovAba][iMovIzq] = cTurn;
        if (cMat[iRenNew][iMovIzq] == cTurnOpp) // A
            cMat[iRenNew][iMovIzq] = cTurn;

}

// determina si el tablero está lleno
bool tableroLleno(char cMat[5][5], int iTamRen, int iTamCol, char cVacant)
{
    for (int iContRen = 0; iContRen < iTamRen; iContRen++)
        for (int iContCol = 0; iContCol < iTamCol; iContCol++)
           if (cMat[iContRen][iContCol] == cVacant)
                return false;
}

// determina si el jugador quiere seguir jugando
bool seguirJugando(char cSeguir)
{
    cout << "Quieres seguir jugando? (s/n) ";
        cin >> cSeguir;
        cSeguir = tolower(cSeguir);
        switch(cSeguir)
        {
            case 's':
                return true;
            case 'n':
                return false;
            default:
                seguirJugando(cSeguir);
        }
}

//Imprime ganador y puntuacion de cada jugador
void puntuacionYGanador(char cMat[5][5], int iTamRen, int iTamCol, char cP1, char cP2)
{
    int iPuntP1 = 0;
    int iPuntP2 = 0;

    for (int iContRen = 0; iContRen < iTamRen; iContRen++)
        for (int iContCol = 0; iContCol < iTamCol; iContCol++)
        {
            if (cMat[iContRen][iContCol] == cP1)
                iPuntP1++;
            else if (cMat[iContRen][iContCol] == cP2)
                iPuntP2++;
        }
        cout << "PUNTUACION" << endl;
        cout << "P1: " << iPuntP1 << endl;
        cout << "P2: " << iPuntP2 << endl;
        if (iPuntP1 > iPuntP2)
            cout << "GANA P1" << endl;
        else if (iPuntP1 < iPuntP2)
            cout << "GANA P2" << endl;
        else if (iPuntP1 == iPuntP2)
            cout << "EMPATE" << endl;
}

//cambia al turno del siguiente jugador
void cambiaTurno(char &cTurn, char &cTurnOpp, int &iTurnCont, char cP1, char cP2)
{
    if (iTurnCont % 2 == 0)
    {
        cTurn = cP1;
        cTurnOpp = cP2;
    }
    else
    {
        cTurn = cP2;
        cTurnOpp = cP1;
    }
    iTurnCont++;
}
int main()
{
    // Inicializaciones
    int iTurnCont, iRenBlob, iColBlob, iTamRen, iTamCol;
    int iMovArr, iMovAba, iMovDer, iMovIzq; // movimientos
    iTamRen = 5;
    iTamCol = 5;
    iTurnCont = 1;
    char cTurn, cTurnOpp, cP1, cP2, cVacant, cMatBoard[5][5], cMov, cSeguir;
    cP1 = 'X';
    cP2 = 'O';
    cVacant = '_';
    cTurn = cP1;
    cTurnOpp = cP2;
    bool bTabLleno, bSeguirJug;
    bTabLleno = true;
    // Funciones
    tableroInit(cMatBoard, iTamRen, iTamCol, cP1, cP2, cVacant);
    do
    {
        muestraTablero(cMatBoard, iTamRen, iTamCol);
        mostrarTurno(cTurn, cP1, cP2);
        preguntaCasilla(cMatBoard, iTamRen, iTamCol, iRenBlob, iColBlob, cTurn);
        preguntaDireccion(cMov);
        asignaMov(iRenBlob, iColBlob, iMovArr, iMovAba, iMovDer, iMovIzq);
        hacerMov(cMatBoard, cMov, iRenBlob, iColBlob, iTamRen, iTamCol,
                 cTurn, cTurnOpp, iMovArr, iMovAba, iMovDer, iMovIzq);
        cout << endl;
        muestraTablero(cMatBoard, iTamRen, iTamCol);
        //Seguir jugando
        bTabLleno = tableroLleno(cMatBoard, iTamRen, iTamCol, cVacant);
        bSeguirJug = seguirJugando(cSeguir);
        if (bTabLleno == false)
        {
            if (bSeguirJug == true)
                cambiaTurno(cTurn, cTurnOpp, iTurnCont, cP1, cP2);
            else if (bSeguirJug == false)
                puntuacionYGanador(cMatBoard, iTamRen, iTamCol, cP1, cP2);
        }
        else
            puntuacionYGanador(cMatBoard, iTamRen, iTamCol, cP1, cP2);
    } while (bSeguirJug == true);

}
