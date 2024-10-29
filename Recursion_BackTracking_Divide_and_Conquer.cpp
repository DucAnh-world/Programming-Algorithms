#include <bits/stdc++.h>
using namespace std;

struct Task{
    string TaskID;
    float StartTime;
    float Duration;

    void show() const{
        cout<<"WorkCode: "<<TaskID<<setw(15)<<"Start Time(gio): "<<StartTime<<setw(15)<<"Duration(gio): "<<Duration<<endl;
    }
};

void HienthiTask(const vector<Task>& Tasks, int index)
{
    if(index < 0)
        return;
    Tasks[index].show();
    HienthiTask(Tasks, index - 1);
}

int CountTasks(const vector<Task>& Tasks, int left, int right)
{
    if(left > right) return 0;
    if(left == right){
        if(Tasks[left].Duration <= 0.5)
        {
            Tasks[left].show();
            return 1;
        }
        else return 0;
    }
    int mid = (left + right) / 2;
    int leftCount = CountTasks(Tasks, left, mid);
    int rightCount = CountTasks(Tasks, mid + 1, right);

    return leftCount + rightCount;
}

void assignTasks(const vector<Task>& tasks, const vector<string>& employees, vector<string>& assignment, vector<bool>& used, int index) {
    if (index == tasks.size()) {  // Khi đã phân công hết tất cả công việc
        for (int i = 0; i < tasks.size(); ++i) {
            cout << tasks[i].TaskID << " -> " << assignment[i] << endl;
        }
        cout << "--------" << endl;
        return;
    }

    // Thử phân công công việc `tasks[index]` cho từng nhân viên
    for (int i = 0; i < employees.size(); ++i) {
        if (!used[i]) {  // Kiểm tra nếu nhân viên chưa được phân công công việc
            used[i] = true;
            assignment[index] = employees[i];
            assignTasks(tasks, employees, assignment, used, index + 1);  // Đệ quy với công việc tiếp theo
            used[i] = false;  // Backtrack
        }
    }
}
int main()
{
    vector<Task> tasks = {
    {"Task1", 9.0, 0.25},   // Bắt đầu lúc 9:00 AM, thời gian thực hiện 0.25 giờ (15 phút)
    {"Task2", 10.0, 0.75},  // Bắt đầu lúc 10:00 AM, thời gian thực hiện 0.75 giờ (45 phút)
    {"Task3", 12.0, 0.5},   // Bắt đầu lúc 12:00 PM, thời gian thực hiện 0.5 giờ (30 phút)
    {"Task4", 14.0, 0.33},  // Bắt đầu lúc 2:00 PM, thời gian thực hiện 0.33 giờ (20 phút)
    {"Task5", 15.0, 0.42},  // Bắt đầu lúc 3:00 PM, thời gian thực hiện 0.42 giờ (25 phút)
    {"Task6", 16.0, 0.83},  // Bắt đầu lúc 4:00 PM, thời gian thực hiện 0.83 giờ (50 phút)
    {"Task7", 17.0, 0.25}   // Bắt đầu lúc 5:00 PM, thời gian thực hiện 0.25 giờ (15 phút)
    };
    vector<string> employees = {
        "Employee1",
        "Employee2",
        "Employee3",
        "Employee4",
        "Employee5",
        "Employee6",
        "Employee7"
    };
    cout<<"\n\t\tDanh sach cong viec"<<endl;
    HienthiTask(tasks, tasks.size() - 1);
    cout<<"\n\t\tDanh sach cong viec co thoi gian thuc hien <= 30p"<<endl;
    int TaskCount = CountTasks(tasks, 0, tasks.size() - 1);
    cout<<"Tong so cong viec tim duoc: "<<TaskCount<<endl;
    cout<<"n\t\tCac cach phan chia cong viec"<<endl;
    vector<string> Giaoviec(7);
    vector<bool> dd(7, false);
    assignTasks(tasks, employees, Giaoviec, dd, 0);
}
