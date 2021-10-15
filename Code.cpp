#include<conio.h>
#include<stdio.h>
#include <iostream>
#include <string.h>
#define MAX 100
using namespace std;
struct Nguoidung
{
	char Hoten[30];
	char gioiTinh[5];
	int Tendangnhap;
	int MSV;
	int Matkhau;
	char Gmail[30];
	char Ngaysinh[10];
};
struct tracnghiem
{
	char noidung[100];
	char dapan[10];
	//cau tra loi;
	char A[100];
	char B[100];
	char C[100];
	char D[100];

};

typedef Nguoidung ND;
void printLine(int n);
void nhap(ND &nd);
void nhapND(ND a[], int n); 
void pressAnyKey(); 
void huongdan(int key);
void capNhatThongTinND(ND &nd) ;
void capNhatND(ND a[], int MSV, int n);
int xoaTheoMSV(ND a[], int MSV, int n); 
void dangnhap();
void showND(ND nd[], int n);

typedef tracnghiem tn;
int chon_cauhoi(struct tracnghiem tn[100],char ketqua[100],int i);
void nhap_cauhoi(struct tracnghiem tn[],int i);
void xuat_cauhoi_chuacodapan(struct tracnghiem tn[],int i);
void xuat_cauhoi(struct tracnghiem tn[],int i);

int main() 
{
    int key;

    ND arrayND[MAX];
    tn arraytn[MAX];
    int soluongND = 0;
	int i,n,dem=0;
	while(true) 
	{
        cout << "CHUONG TRINH QUAN LY THI TRAC NGHIEM C/C++\n";
        cout << "*************************MENU**************************\n";
        cout << "**  1. Huong dan.                                    **\n";
        cout << "**  2. Them nguoi dung.                              **\n";
        cout << "**  3. Tao de thi.                                   **\n";
        cout << "**  4. Thi.                                          **\n";
        cout << "**  5. Sua thong tin nguoi dung.                     **\n";
        cout << "**  6. Xoa nguoi dung.                               **\n";
        cout << "**  7. Dang nhap.                                    **\n"; 
        cout << "**  8. Hien thi danh sach thi sinh.                  **\n";		        
        cout << "**  0. Dang xuat                                     **\n";
        cout << "*******************************************************\n";
        cout << "Nhap tuy chon: ";
        cin >> key;
        switch(key)
		{
            case 1:
                cout << "\n1. Huong dan.";	
				huongdan( key);
                pressAnyKey();
                break;						
            case 2:
                cout << "\n2. Them nguoi dung.";
                nhapND(arrayND, soluongND);
                printf("\nThem nguoi dung thanh cong!");
                soluongND++;
                pressAnyKey();
                break;
            case 3:
            	cout<< "\n3. Tao de thi.";
            		printf("\nNhap vao so luong cau hoi : ");
					scanf("%d",&n);
					for(i=1;i<=n;i++)
					{
						nhap_cauhoi(arraytn,i);
						//	chon_cauhoi(t,i);
						//if(chon_cauhoi(t,i)) dem++;
					}

					for(i=1;i<=n;i++)
					{
						xuat_cauhoi_chuacodapan(arraytn,i);
						//	xuat_cauhoi(t,i);
					}
                pressAnyKey();
                break;					
			case 4:
				cout<< "\n4. Thi.";
				for(i=1;i<=n;i++)
				{
					xuat_cauhoi_chuacodapan(arraytn,i);
					//	xuat_cauhoi(t,i);
				}
				char traloi[100];	
				printf("\n Tra loi cau hoi: ");
				for(i=1;i<=n;i++)
				{
					printf("\nDap an %d: ",i);
					fflush(stdin);
					gets(traloi);
				}
				printLine(40);	
				printf("\n\nKet qua bai thi");
				for(i=1;i<=n;i++)
				{
				//	xuat_cauhoi_chuacodapan(t,i);
				xuat_cauhoi(arraytn,i);
				}
                pressAnyKey();
                break;
            case 5:
                if(soluongND > 0) {
                    int MSV;
                    cout << "\n5. Sua thong tin nguoi dung. ";
                    cout << "\n Nhap MSV: "; cin >> MSV;
                    capNhatND(arrayND, MSV, soluongND);
                }else{
                    cout << "\nDanh sach nguoi dung trong!";
                }
                pressAnyKey();
                break;
            case 6:
                if(soluongND > 0) {
                    int MSV;
                    cout << "\n6. Xoa nguoi dung.";
                    cout << "\nNhap MSV: "; cin >> MSV;
                    if (xoaTheoMSV(arrayND, MSV, soluongND) == 1) 
					{
                        soluongND--;
                    }
                }else{
                    cout << "\nDanh sach nguoi dung trong!";
                }
                pressAnyKey();
                break;
			case 7:
				cout <<"\n7. Dang nhap";
				dangnhap();
                pressAnyKey();
                break;
			case 8:
                if(soluongND > 0){
                    cout << "\n8. Hien thi danh sach thi sinh.";
                    showND(arrayND, soluongND);
                }else{
                    cout << "\nDanh sach thi sinh trong!";
                }
                pressAnyKey();
                break;				        	
            case 0:
                cout << "\nBan da chon thoat chuong trinh!";
                getch();
                return 0;
            default:
                cout << "\nKhong co chuc nang nay!";
                cout << "\nHay chon chuc nang trong hop menu.";
                pressAnyKey();
                break;					
    	}
	}
}



void huongdan(int key)
{
    printLine(40);   
	cout << "\n1. Huong dan Them nguoi dung.";
	cout << "\nBam phim 2 de thuc hien chuc nang them nguoi dung";
	cout << "\nsau do nhap day du thong tin hien thi.";	
	printLine(40);
	cout << "\n2. Huong dan Tao de thi.";
	cout << "\nBam phim 3 de thuc hien chuc nang tao de thi,";
	cout << "\nsau do nhap vao so luong cau hoi ban muon tao,";
	cout << "\nnhap noi dung, dap an tung cau va dap an dung.";
	cout << "\nLuu y: 'Chuc nang nay chi danh cho giao vien'";
	printLine(40);
	cout << "\n3. Huong dan vao thi.";
	cout << "\nBam phim 4 de vao thi. Sau do, ban hay chon dap an minh cho la dung";
	printLine(40);
	cout << "\n4. Huong dan sua thong tin nguoi dung.";
	cout << "\nBam phim 5 va nhap cac thong tin can thiet";
	printLine(40);
	cout << "\n5. Huong xoa nguoi dung.";	
	cout << "\nBam phim 6 de thuc hien chuc nang nay. Sau do,";
	cout << "\nban nhap MSV cua thi sinh can xoa, chuc nang nay danh cho 'Giang Vien'";
	printLine(40);
	cout << "\n6. Huong dang nhap.";
	cout << "\nBam phim 7 de dang nhap. Sau do, ban nhap tai khoan duoc cap";
	cout << "\7. Huong dan Dang xuat";
	cout << "\nBam phim 0 de thoat khoi he thong.";
	printLine(40);
}

void nhap(ND &nd)
{
	cout<<"\nHo ten: "; fflush(stdin); gets(nd.Hoten);
	cout<<"Nhap gioi tinh: "; gets(nd.gioiTinh);
	cout<<"Ngay sinh: ";fflush(stdin); gets(nd.Ngaysinh);
	cout<<"Gmail: ";fflush(stdin); gets(nd.Gmail);
	cout<<"Ten dang nhap: ";cin>>nd.Tendangnhap;
	cout<<"Ma sinh vien: ";cin>>nd.MSV;
	cout<<"Mat khau: ";
	while(true)
        {
            nd.Matkhau = _getch();
            _putch('*');
            if (nd.Matkhau == 13) break;
        }
	//cin>>nd.Matkhau;
	cout<<endl<<"Xac nhan mat khau: ";
	while(true)
        {
            nd.Matkhau = _getch();
            _putch('*');
            if (nd.Matkhau == 13) break;
        }
	
	//cin>>nd.Matkhau;
}
void nhapND(ND a[], int n) 
{
    printLine(40);
    printf("\nNhap nguoi dung thu %d:", n + 1);
    nhap(a[n]);
    printLine(40);
}
void printLine(int n) 
{
    cout << endl;
    for (int i = 0; i < n; i++) 
	{
        cout << "_";
    }
    cout << endl;
}
void pressAnyKey() 
{
    cout << "\n\nBam phim bat ky de tiep tuc...";
    getch();
    system("cls");
}
int chon_cauhoi(struct tracnghiem tn[100],char ketqua[100],int i)
{

	//int dem=0;
	//printf("\nchon dap an tra loi cau hoi %d ",i);

	if(strcmp(tn[i].dapan,ketqua)==0)

		return 0;

}

void nhap_cauhoi(struct tracnghiem tn[],int i)
{
	printf("Nhap vao cau hoi thu %d ",i);
	printf("\nNhap vao noi dung cau hoi: ");
	fflush (stdin);
    scanf(tn[i].noidung);
    gets(tn[i].noidung);

   //if(tn[i].dapan!='A' && tn[i].dapan!='B' && tn[i].dapan!='C' && tn[i].dapan!='D')
   //{
	//    printf("\nnhap khong dung dap an");
   //}
    printf("Nhap vao noi dung dap an A. ");
    gets(tn[i].A);
    printf("Nhap vao noi dung dap an B. ");
    gets(tn[i].B);
    printf("Nhap vao noi dung dap an C. ");
    gets(tn[i].C);
    printf("Nhap vao noi dung dap an D. ");
    gets(tn[i].D);
     printf("Nhap dap an: ");
     // scanf("%c",tn[i].dapan);
     gets(tn[i].dapan);

}
void xuat_cauhoi_chuacodapan(struct tracnghiem tn[],int i)
{
	printLine(40);
	printf("\nCau %d ",i);
	printf("\n\t %s ",tn[i].noidung);
//	printf("\n Dap an dung la  %s ",tn[i].dapan);
//	printf("\n");
	printf("\n A: %s \t\t B: %s \t\t C: %s \t\t D: %s \t\t ",tn[i].A,tn[i].B,tn[i].C,tn[i].D);
	printf("\n");

}
void xuat_cauhoi(struct tracnghiem tn[],int i)
{
	printf("\nCau %d ",i);
	printf("\n Dap an dung la  %s ",tn[i].dapan);
}
void capNhatThongTinND(ND &nd) 
{
	cout<<"\nHo ten: "; fflush(stdin); gets(nd.Hoten);
	cout<<"Nhap gioi tinh: "; gets(nd.gioiTinh);
	cout<<"Ngay sinh: ";fflush(stdin); gets(nd.Ngaysinh);
	cout<<"Gmail: ";fflush(stdin); gets(nd.Gmail);
	cout<<"Ten dang nhap: ";cin>>nd.Tendangnhap;
	cout<<"Ma sinh vien: ";cin>>nd.MSV;
}
void capNhatND(ND a[], int MSV, int n) 
{
    int found = 0;
    for(int i = 0; i < n; i++) {
        if (a[i].MSV == MSV) {
            found = 1;
            printLine(40);
            cout << "\n Cap nhat thong tin nguoi dung co MSV = " << MSV;
            capNhatThongTinND(a[i]);
            printLine(40);
            break;
        }
    }
    if (found == 0) {
        printf("\n Nguoi dung co MSV = %d khong ton tai.", MSV);
    }
}
int xoaTheoMSV(ND a[], int MSV, int n) 
{
    int found = 0;
    for(int i = 0; i < n; i++) {
        if (a[i].MSV == MSV) {
            found = 1;
            printLine(40);
            for (int j = i; j < n; j++) {
                a[j] = a[j+1];
            }
            cout << "\n Da xoa nguoi dung co MSV = " << MSV;
            printLine(40);
            break;
        }
    }
    if (found == 0) {
        printf("\n Nguoi dung co MSV = %d khong ton tai.", MSV);
        return 0;
    } else {
        return 1;
    }
}
void dangnhap()
{
    char username[] = "2051060736";
    char passwrod[] = "2051060736";
    char user[50], pass[50]; 
    printf("\nTen tai khoan: ");
    fflush(stdin);
    gets(user);
    printf("Mat khau: ");
    fflush(stdin);
    gets(pass);
    while(strcmp(user, username) != 0 || strcmp(pass, passwrod) != 0) {
        printf("Tai khoan hoac mat khau khong ton tai !\n");
        printf("Ten tai khoan: ");
        fflush(stdin);
        gets(user);
        printf("Mat khau: ");
        fflush(stdin);
        gets(pass);
    }
    printf("Dang nhap thanh cong !\n");	
}
void showND(ND nd[], int n)
{
    printLine(100);
    cout <<"\n\tSTT\tMSV\t\tHo va ten\tGioi tinh\tGmail";
    for(int i = 0; i < n; i++) {
        // in sinh vien thu i ra man hinh
        printf("\n\t%d", i + 1);
        printf("\t%d", nd[i].MSV);
        printf("\t%s", nd[i].Hoten);
        printf("\t%s", nd[i].gioiTinh);
        printf("\t\t%s",nd[i].Gmail);
    }
    printLine(100);
}
  
