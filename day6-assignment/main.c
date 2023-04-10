#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
#include<ctype.h>
#include <string.h>

typedef struct Date{
    int ngay;
    int thang;
    int nam;
}Date;
typedef struct NhanVien{
    int ma;
    char ho[20];
    char ten[20];
    Date ngaySinh;
    char noiSinh[100];
    char diaChi[200];
    float luong;
    Date ngayVao;
}NhanVien;
typedef struct Node{
    NhanVien nhanVien;
    struct Node *next;
}Node;
typedef struct DanhSach{
    Node *pHead;
    int n;
}DanhSach;

// Prototypes
//Khởi tạo danh sách
void khoiTaoDanhSach(DanhSach *danhSach);
//Tạo 1 node 
Node *taoNode(NhanVien nhanVien);
void swap(Node *a, Node *b);
void freeMemory(DanhSach *danhSach);
void toString(char str[],int num);
//Hàm kiểm tra xem năm có phải năm nhuận hay không
int kiemTraNamNhuan(int nam);
//Hàm kiểm tra ngày tháng có hợp lệ hay không
int kiemTraNgayThang(Date *ngayThang);
//Kiểm tra xem mã nhân viên đã tồn tại trong danh sách hay chưa
int kiemTraMaNV(DanhSach danhSach,int ma);
//Hàm kiểm tra xem năm có phải năm nhuận hay không
int kiemTraNamNhuan(int nam);
//Hàm kiểm tra ngày tháng có hợp lệ hay không
int kiemTraNgayThang(Date *ngayThang);
//Kiểm tra xem mã nhân viên đã tồn tại trong danh sách hay chưa
int kiemTraMaNV(DanhSach danhSach,int ma);
// Hàm hiển thị menu
void menu();
//Hàm nhập ngày tháng năm
void nhapNgayThang(Date *ngayThang);
//Hàm nhập thông tin cho nhân viên
NhanVien nhapNhanVien();
//Hàm hiển thị thông tin nhân viên
void xuatNhanVien(NhanVien n);
//Hàm hiển thị ngày tháng năm
void xuatNgayThang(char date[],Date ngayThang);
//Hàm thêm nhân viên vào danh sách
void nhapDanhSach(DanhSach *danhSach);
//Hàm hiển thị tất cả nhân viên trong danh sachs
void xuatDanhSach(DanhSach danhSach);
//Hàm tìm kiếm nhân viên theo tên
void timTheoTen(DanhSach danhSach,char ten[],DanhSach *ketQua);
//Hàm thêm nhân viên vào danh sách
void themNhanVien(DanhSach *danhSach,NhanVien n,int viTri);
//Hàm tìm nhân viên theo mã
void timTheoMa(DanhSach danhSach, int ma,DanhSach *ketQua);
//Hàm xóa nhân viên theo má
void xoaNhanVien(DanhSach *danhSach, int ma);
//Hàm xắp xếp danh sách theo Lương
void xapSepTheoLuong(DanhSach *danhSach);

int main(){
    int chon,ma,k;
    char ten[20];
    DanhSach danhSach;
    DanhSach timKiem;
    Date ngayThang;
    NhanVien nhanVien;
    // Khởi tạo danh sách
    khoiTaoDanhSach(&danhSach);
    do{
        menu();
        scanf("%d",&chon);
        switch(chon){
            case 1:
                k = 0;
                if(danhSach.pHead != NULL){
                    printf("Nhap vi tri muon them: ");
                    scanf("%d",&k);
                }
                nhanVien = nhapNhanVien();
                while(kiemTraMaNV(danhSach,nhanVien.ma)){
                    printf("Ma %d da ton tai!\n",nhanVien.ma);
                    printf("Nhap lai ma: ");
                    scanf("%d",&nhanVien.ma);
                }
                themNhanVien(&danhSach,nhanVien,k);
                break;
            case 2:
                khoiTaoDanhSach(&timKiem);
                printf("Nhap ma muon tim: ");
                scanf("%d",&ma);
                timTheoMa(danhSach,ma,&timKiem);
                xuatDanhSach(timKiem);
                freeMemory(&timKiem);
                break;
            case 3:
                khoiTaoDanhSach(&timKiem);
                fflush(stdin);
                printf("Nhap ten muon tim: ");
                gets(ten);
                timTheoTen(danhSach,ten,&timKiem);
                xuatDanhSach(timKiem);
                freeMemory(&timKiem);
                break;
            case 4:
                xapSepTheoLuong(&danhSach);
                xuatDanhSach(danhSach);
                break;
            case 5:
                printf("Nhap ma muon xoa: ");
                scanf("%d",&ma);
                xoaNhanVien(&danhSach,ma);
                break;
            case 0:
                freeMemory(&danhSach);
                break;
            default:
                printf("Chuc nang khong ton tai!\n");
        }
    }while(chon != 0);
    freeMemory(&danhSach);
    return 0;
}

void menu(){
    printf("\n\t****************MENU****************\n");
    printf("\t1.Them vao 1 nhan vien.\n");
    printf("\t2.Tim nhan vien theo ma.\n");
    printf("\t3.Tim nhan vien theo ten.\n");
    printf("\t4.Bang luong cua nhan vien giam dan.\n");
    printf("\t5.Xoa 1 nhan vien theo ma.\n");
    printf("\t0.Thoat chuong trinh.\n");
    printf("\t************************************\n");
    printf("\t==> Chon 1 chuc nang: ");
}
void khoiTaoDanhSach(DanhSach *danhSach){
    danhSach->pHead = NULL;
    danhSach->n = 0;
}
int kiemTraNamNhuan(int nam){
    // Kiểm tra nếu là năm nhuận trả về 1 ngược lại trả về 0
    if(nam % 4 == 0 || (nam % 100 == 0 && nam % 400 == 0)){
        return 1;
    }
    return 0;
}
int kiemTraNgayThang(Date *ngayThang){
    int t = ngayThang->thang;
    int n = ngayThang->ngay;
    switch(t){
        case 1: case 3: case 5: case 7: case 8: case 10: case 12: // Những tháng có 31 ngày
            if(n < 0 || n > 31){ // Nếu ngày > 31 xuất thông báo k hợp lệ trả về 0
                printf("Ngay %d Thang %d Nam %d khong hop le!\n",n,t,ngayThang->nam);
                return 0;
            }
            break;
        case 4: case 6: case 9: case 11: // Những tháng  có 30 ngày
            if(n < 0 || n > 30){ // Nếu ngày > 30 xuất thông báo k hợp lệ trả về 0
                printf("Ngay %d Thang %d Nam %d khong hop le!\n",n,t,ngayThang->nam);
                return 0;
            }
            break;
        case 2:
            if(kiemTraNamNhuan(ngayThang->nam)){ // Kiểm tra năm nhuận tháng có 29 ngày
                if(n < 0 || n > 29){
                    printf("Ngay %d Thang %d Nam %d khong hop le!\n",n,t,ngayThang->nam);
                    return 0;
                }
            }else{ // Không là năm nhuận chỉ có 28 ngày
                if(n < 0 || n > 28){
                printf("Ngay %d Thang %d Nam %d khong hop le!\n",n,t,ngayThang->nam);
                return 0;
                }
            }
            break;
        default: 
            printf("Ngay %d Thang %d Nam %d khong hop le!\n",n,t,ngayThang->nam);
            return 0;
    }
    return 1;
}
void nhapNgayThang(Date *ngayThang){
    printf("Nhap ngay: ");
    scanf("%d",&ngayThang->ngay);
    printf("Nhap thang: ");
    scanf("%d",&ngayThang->thang);
    printf("Nhap nam: ");
    scanf("%d",&ngayThang->nam);
    if(!kiemTraNgayThang(ngayThang)){ 
        // Nếu ngày tháng không hợp lệ xuất thông báo và yêu cầu nhập lại
        printf("Vui long nhap lai!\n");
        nhapNgayThang(ngayThang);
    }
}
int kiemTraMaNV(DanhSach danhSach,int ma){
    Node *pTmp = danhSach.pHead;
    while(pTmp != NULL){
        if(pTmp->nhanVien.ma == ma) // Nếu tìm thấy mã trả về 1
            return 1;
        pTmp = pTmp->next;
    }
    return 0; // Không tìm thấy mã trả về 0
}
NhanVien nhapNhanVien(){
    printf("Nhap thong tin nhan vien.\n");
    NhanVien nhanVien;
    printf("Nhap ma nv: ");
    scanf("%d",&nhanVien.ma);
    fflush(stdin);
    printf("Nhap ho: ");
    // scanf("%s",nhanVien.ho);
    gets(nhanVien.ho);
    printf("Nhap ten:");
    // scanf("%s",nhanVien.ten);
    gets(nhanVien.ten);
    printf("Nhap ngay sinh: \n");
    nhapNgayThang(&nhanVien.ngaySinh);
    fflush(stdin);
    printf("Nhap noi sinh: ");
    // scanf("%s",nhanVien.noiSinh);
    gets(nhanVien.noiSinh);
    // fflush(stdin);
    printf("Nhap dia chi: ");
    // scanf("%s",nhanVien.diaChi);
    gets(nhanVien.diaChi);
    // fflush(stdin);
    printf("Nhap luong:");
    scanf("%f",&nhanVien.luong);
    printf("Nhap ngay vao:\n");
    nhapNgayThang(&nhanVien.ngayVao);
    return nhanVien;
}
Node *taoNode(NhanVien nhanVien){
    Node *node = malloc(sizeof(Node)); // Khởi tạo 1 node
    if(node != NULL){ // Nếu khởi tạo thành công
        node->nhanVien = nhanVien;
        node->next = NULL;
    }else{ // Khởi tạo thất bại xuất thông báo
        printf("Tao node that bai!\n");
    }
    return node;
}
void themNhanVien(DanhSach *danhSach,NhanVien n,int viTri){
    Node *node = taoNode(n);
    if(danhSach->pHead == NULL){
        danhSach->pHead = node;
        danhSach->n += 1;
    }
    else{ 
        if((viTri < 0 || viTri >= danhSach->n)){
            // Nếu vị trí thêm không hợp lệ xuất thông báo
            printf("Vi tri them khong hop le!\n");
            printf("Vi tri phai >=0 va < %d\n",danhSach->n);
            printf("Nhap lai vi tri: ");
            scanf("%d",&viTri);
            themNhanVien(danhSach,n,viTri); 
            free(node);
        } else if(viTri == 0){ // Nếu vị trí thêm ở đầu danh sách dịch chuyển pHead trỏ tới node
            node->next = danhSach->pHead;
            danhSach->pHead = node;
            danhSach->n += 1; // Tăng số lượng nhân viên trong danh sách lên 1
        } else { // Nếu vị trí khác đầu và cuối
        // Tạo 1 node trỏ tới node ở vị trí insert
            Node *pIns = danhSach->pHead;
            // Tạo 1 node trỏ tới vị trí trước node insert
            Node *pPre = NULL;
            int i = 0;
            while(pIns != NULL){
                if(i == viTri) break; // Nếu pIns trỏ tới node ở vị trí insert dừng lại
                pPre = pIns;
                pIns = pIns->next;
                i++;
            }
            // Node trước vị trí insert sẽ trỏ tới node mới thêm
            pPre->next = node;
            // Node mới thêm sẽ trỏ tới node ở vị trí insert
            node->next = pIns;
            danhSach->n += 1; // Tăng số lượng nhân viên trong danh sách lên 1
        }
    }
}
void xuatNgayThang(char date[],Date ngayThang){
    char ngay[10];
    toString(ngay,ngayThang.ngay);
    char thang[10];
    toString(thang,ngayThang.thang);
    char nam[10];
    toString(nam,ngayThang.nam);
    strcpy(date,ngay);
    strcat(date,"/");
    strcat(date,thang);
    strcat(date,"/");
    strcat(date,nam);
}
void xuatNhanVien(NhanVien n){
    char ngaySinh[12],ngayVao[12];
    xuatNgayThang(ngaySinh,n.ngaySinh);
    xuatNgayThang(ngayVao,n.ngayVao);
    printf("%-5d%-15s%-10s%-15s%-15s%-15s%-10.2f%-10s\n",
    n.ma,(n.ho),(n.ten),ngaySinh,
    (n.noiSinh),(n.diaChi),n.luong,ngayVao);
}
void xuatDanhSach(DanhSach danhSach){
    Node *pTmp = danhSach.pHead;
    if(pTmp == NULL){
        printf("Danh sach rong!\n");
    }else{
        printf("%-5s%-15s%-10s%-15s%-15s%-15s%-10s%-10s\n",
        "Ma","Ho","Ten","Ngay Sinh","Noi Sinh","Dia Chi","Luong","Ngay Vao");
        while(pTmp != NULL){
        xuatNhanVien(pTmp->nhanVien);
        pTmp = pTmp->next;
    }
    }
}
void xapSepTheoLuong(DanhSach *danhSach){
    if(danhSach->pHead != NULL){
        int swapp, i;
        Node *ptr1;
        Node *lptr = NULL;

        /* Checking for empty   danhSach */
        if (danhSach == NULL)
            return;

        do
        {
            swapp = 0;
            ptr1 = danhSach->pHead;

            while (ptr1->next != lptr)
            {
                if (ptr1->nhanVien.luong < ptr1->next->nhanVien.luong)
                {
                    swap(ptr1, ptr1->next);
                    swapp = 1;
                }
                ptr1 = ptr1->next;
            }
            lptr = ptr1;
        }
        while (swapp);
    }
}
void freeMemory(DanhSach *danhSach){
    while(danhSach->pHead != NULL){
        Node *pTmp = danhSach->pHead;
        danhSach->pHead = pTmp->next;
        pTmp->next = NULL;
        free(pTmp);
        pTmp = NULL;
    }
    printf("Complete misson.\n");
}
void swap(Node *a, Node *b){
    NhanVien temp = a->nhanVien;
    a->nhanVien = b->nhanVien;
    b->nhanVien = temp;
}
void toString(char str[],int num)
{    
    int i, rem, len = 0, n;

    n = num;
    while (n != 0)
    {
        len++;
        n /= 10;
    }
    for (i = 0; i < len; i++)
    {
        rem = num % 10;
        num = num / 10;
        str[len - (i + 1)] = rem + '0';
    }
    str[len] = '\0';
}
void xoaNhanVien(DanhSach *danhSach, int ma){
    Node *pDel = danhSach->pHead;
    if(pDel == NULL){
        printf("danhSach dang trong!");
    }else{
        Node *pPre = NULL;
        while(pDel != NULL){
            if(pDel->nhanVien.ma == ma) break;
            pPre = pDel;
            pDel = pDel->next;
        }
        if(pDel == NULL){
            printf("Khong tim thay ma!\n");
        }else{
            if(pDel == danhSach->pHead){
                danhSach->pHead = pDel->next;
                pDel->next = NULL;
                free(pDel);
            }else{
                pPre->next = pDel->next;
                pDel->next = NULL;
                free(pDel);
            }
        }
    }
}
void timTheoTen(DanhSach danhSach, char ten[], DanhSach *ketQua){
    Node *pTmp = danhSach.pHead;
    if(pTmp == NULL){
        printf("Danh sach rong!\n");
        return;
    }
    while(pTmp != NULL){
        if(strcmp(pTmp->nhanVien.ten,ten) == 0){
            themNhanVien(ketQua,pTmp->nhanVien,0);
        }
        pTmp = pTmp->next;
    }
}
void timTheoMa(DanhSach danhSach, int ma,DanhSach *ketQua){
    Node *pTmp = danhSach.pHead;
    if(pTmp == NULL){
        printf("Danh sach rong!\n");
        return;
    }
    while(pTmp != NULL){
        if(pTmp->nhanVien.ma == ma){
            themNhanVien(ketQua,pTmp->nhanVien,0);
            return;
        }
        pTmp = pTmp->next;
    }
}



