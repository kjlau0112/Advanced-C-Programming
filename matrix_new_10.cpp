#include <iostream>
#include <cstdarg>
#include <string.h>
#include <stdlib.h> //malloc and free
#include <cstring>
using namespace std;
#define NOI(_arr1D)   (sizeof(_arr1D)/sizeof(_arr1D[0]))
#define NoRows(_arr2D)   NOI(_arr2D)
#define NoCols(_arr2D)   NOI(_arr2D[0])
#define ShowMatrix(_n)   _ShowMatrix(NoRows(_n),NoCols(_n),(int *)&_n)

template <typename T>
class Matrix;

template<typename T>
ostream & operator<<(ostream &os, const Matrix<T> &m);

template <typename T>
class Matrix 
{
	int NRows;
	int NCols;
	T *cells;
	Matrix(int nRows, int nCols, T*cells):NRows(nRows),NCols(nCols),cells(cells)
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
		
//		int& Cell(int r, int c)const 
//		{
//			return cells[r*NCols +c];
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
						cs[r*rhs.NCols+c]+= (*this)[r][i]*rhs[i][c];
					}
				}
			}
			return Matrix(NRows,rhs.NCols,cs);
		}
	 Matrix operator+(const Matrix& rhs)const
	 {
	    if(NCols != rhs.NRows) throw "Cannot Add lahh...";
	    if(NRows != rhs.NCols) throw "Cannot Add lahh...";
	    int* cs=new int[NRows*NCols]; // lhs Row, rhs Col
	    for (int r=0; r<NRows; r++){
	        for (int c=0; c<NCols;c++){
	              //  cs[r*NCols+c] = Cell(r,c) + rhs.Cell(r,c);
	                 cs[r*NCols+c] = (*this)[r][c]+ (*this)[r][c];
	        }
	    }
	    return Matrix(NRows, NCols, cs); // Returning a new matrix, i.e. instantiation
    }
  	 Matrix operator~()const{
        int* cs=new int[NCols*NRows]; // lhs Row, rhs Col
        for (int c=0; c<NCols;c++){
            for (int r=0; r<NRows; r++){
                for (int i=0; i<NRows;i++){
               // cs[c*NRows+r] = Cell(r,c);
               cs[c*NRows+r] = (*this)[r][c];
                
            }
        }
    }
        return Matrix(NCols, NRows, cs); // Returning a new matrix, i.e. instantiation
    }
    
    friend ostream& operator<<(ostream& os, const Matrix &m);
	
	Matrix operator = (const Matrix &rhs)
	{
		delete [] cells;
		NRows =rhs.NRows;
		NCols= rhs.NCols;
		cells = new int[NRows*NCols];
		memcpy(cells,rhs.cells,NRows*NCols*sizeof(int));
		return *this;
	}
	
	bool operator ==(const Matrix& rhs)const
	{
		if(NRows != rhs.NRows) return false;
		if(NCols != rhs.NCols) return false;
		for (int i =0; i<(NRows*NCols);i++)
		if(cells[i]!=rhs.cells[i]) return false;
		return true;
	}
	
	bool operator !=(const Matrix& rhs)const
	{
		return!(*this ==rhs);
	}
	
	int & operator[] (const char* what)const 
	{
		if(strcmp(what,"MAX")==0)
		{
			int max =0;
			for(int i=1; i<(NRows*NCols);i++)
			{
				if(cells[max]<<cells[i]) max =i;
			}
			return cells[max];
		}
		else
		{
			if(strcmp(what,"MIN")==0)
			{
				int min =0;
				for(int i=1; i<(NRows*NCols);i++)
				{
					if(cells[min]<<cells[i]) min =i;
				}
				return cells[min];
			}
			
		}
		throw "Invalid option!";
	}
	int *operator[] (int n)const
	{
		return &cells[n*NCols];
	}
	
	Matrix operator++() //++m
	{
		int *cell= cells;
		for(int i = 0;i<(NCols*NRows);i++,cell++)(*cell)++;
		return *this;
	}
	
	Matrix operator++(int  )//m++
	{
		Matrix old =*this;
		++*this;
		return old;
	}
	
	//Matrix operator* (const Matrix& rhs)const 
	Matrix operator*(int rhs)const 
	{
		int * cs = new int[NRows*NCols];
		for(int i =0; i<(NRows*NCols);i++)
		{
			cs[i]= rhs*cells[i];

		}
		return Matrix(NRows,NCols,cs);
	}
	void *operator new(size_t size)
	{
		//Matrix *p :: New Matrix();
		cout<<"Overloading new operator with size"<<size<<endl;
		void *p =malloc(size);
		return p;		
	}
	void operator delete (void *p)
	{
		cout<<"Overloading delete operator"<<endl;
		free(p);		
	}
	
};

Matrix operator*(int lhs, const Matrix &rhs)
{
	return rhs*lhs;
}
	
ostream &operator <<(ostream& os, const Matrix &m)
{
	// Tale mote that t
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
Matrix *pm =new  Matrix(2,2, //mew the col and row
						2,4,
						6,8);
cout<<"mA"<<endl<<mA<<endl;
cout<<"pm"<<endl<<*pm<<endl;
delete pm;
	
return 0;
}
