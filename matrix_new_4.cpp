#include <iostream>
#include <cstdarg>
using namespace std;
#define NOI(_arr1D)   (sizeof(_arr1D)/sizeof(_arr1D[0]))
#define NoRows(_arr2D)   NOI(_arr2D)
#define NoCols(_arr2D)   NOI(_arr2D[0])
#define ShowMatrix(_n)   _ShowMatrix(NoRows(_n),NoCols(_n),(int *)&_n)

class Matrix 
{
	int NRows;
	int NCols;
	int *cells;
	Matrix(int nRows, int nCols, int*cells):NRows(nRows),NCols(nCols),cells(cells)
	{
		
	}
	public:
		Matrix(int nRows, int nCols,...):NRows(nRows),NCols(nCols) // copy ctor
		{
			cells =new int [nRows*nCols];
			va_list args;
			va_start(args,nCols);
			for(int i =0; i <(nRows*nCols);i++)
			{
				cells[i]= va_arg(args, int);
			}
			va_end(args);
		}
		Matrix(const Matrix &m) // copy ctor
		{
			NRows = m.NRows;
			NCols =m.NCols;
			cells =new int [NRows*NCols];
			memcpy(cells,m.cells,NRows*sizeof(int));
		}
		~Matrix()
		{
			delete [] cells;
		}
		
		int& Cell(int r, int c)const 
		{
			return cells[r*NCols +c];
		}
//		void Show()
//		{
//			for(int r=0; r<NRows;r++)
//			{
//				for(int c=0; c<NCols;c++) cout<<Cell(r,c)<<'\t';
//				cout<<endl;
//				
//			}
//		}

		
		Matrix operator* (const Matrix& rhs)const 
		{
			if(NCols !=rhs.NRows) throw"Cannnot multiply";
			
			int * cs = new int[NRows*rhs.NCols];
			for(int r =0; r<NRows;r++)
			{
				for(int c=0 ;c<rhs.NCols;c++)
				{
					cs[r*rhs.NCols+c]=0;
					for(int i =0;i<rhs.NRows;i++)
					{
						cs[r*rhs.NCols+c]+= Cell(r,i)*rhs.Cell(i,c);
					}
				}
			}
			return Matrix(NRows,rhs.NCols,cs);
		}
			 Matrix operator+(const Matrix& rhs)const{
            if(NCols != rhs.NRows) throw "Cannot Add lahh...";
            if(NRows != rhs.NCols) throw "Cannot Add lahh...";
            int* cs=new int[NRows*NCols]; // lhs Row, rhs Col
            for (int r=0; r<NRows; r++){
                for (int c=0; c<NCols;c++){
                        cs[r*NCols+c] = Cell(r,c) + rhs.Cell(r,c);
                }
            }
            return Matrix(NRows, NCols, cs); // Returning a new matrix, i.e. instantiation
        }
	   Matrix operator~()const{
            int* cs=new int[NCols*NRows]; // lhs Row, rhs Col
            for (int c=0; c<NCols;c++){
                for (int r=0; r<NRows; r++){
                    for (int i=0; i<NRows;i++){
                    cs[c*NRows+r] = Cell(r,c);
                }
            }
        }
        return Matrix(NCols, NRows, cs); // Returning a new matrix, i.e. instantiation
    }
    friend ostream& operator<<(ostream& os, const Matrix &m);
	

};

ostream &operator <<(ostream& os, const Matrix &m)
{
	for(int r =0; r<m.NRows;r++)
	{
		for(int c=0; c<m.NCols;c++)
		{
			os<<m.cells[r*m.NCols+c]<<'\t';
		}
		os<<endl;
	}
	return os;
}

void _ShowMatrix(int nR,int nC,int *m)
{
	for(int r=0;r<nR;r++)
	{
		cout<<*m<<"\t";
		for(int c=0;c<nC;c++) cout<<m[r*nC+c]<<'\t';
		cout<<endl;
	}
}

main()
{

	Matrix mA
		(3,2,
		1,2,
		3,4,
		5,6);

	
	Matrix mB(2,2,
              1,2,
              3,4);
		
	Matrix mC(3,3,
              1,5,0,
              4,8,7,
              9,1,2);
	

	try
	{
		Matrix mC =mA*mB;
	//	cout<<endl;
	cout<<mA;
		//operator<<(cout,mA);
		cout<<"   x"<<endl;
		cout<<mB;
		cout<<"   ="<<endl;
		cout<<mC;
	}


	catch (const char *msg)
	{
		cout<<msg<<endl;
	}
	return 0;
}
