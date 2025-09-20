#include "../include.h"

class TaskManager {
public:
    // assumes each taskId is unique, so that two users cant have the same taskId
    unordered_map<int, int> task_priority, task_user;
    
    struct Triplet {
        int uid, tid, p;
    };
    
    struct Compare {
        bool operator()(const Triplet& a, const Triplet& b) const {
            if (a.p > b.p) return true;
            if (a.p < b.p) return false;

            return a.tid > b.tid;
        }
    };

    set<Triplet, Compare> priority_list;

    TaskManager(vector<vector<int>>& tasks) {
        for (const auto& task : tasks) {
            task_priority[task[1]] = task[2];
            task_user[task[1]] = task[0];

            priority_list.insert({task[0], task[1], task[2]});
        }
    }
    
    void add(int userId, int taskId, int priority) {
        task_priority[taskId] = priority;
        task_user[taskId] = userId;

        priority_list.insert({userId, taskId, priority});
    }
    
    void edit(int taskId, int newPriority) {
        int old = task_priority[taskId];
        task_priority[taskId] = newPriority;

        priority_list.erase({task_user[taskId], taskId, old});
        priority_list.insert({task_user[taskId], taskId, newPriority});
    }
    
    void rmv(int taskId) {
        priority_list.erase({task_user[taskId], taskId, task_priority[taskId]});
        task_user.erase(taskId);
        task_priority.erase(taskId);
    }
    
    int execTop() {
        if (priority_list.empty()) return -1;

        int uid = priority_list.begin()->uid;
        int tid = priority_list.begin()->tid;
        
        priority_list.erase(priority_list.begin());
        task_priority.erase(tid);
        task_user.erase(tid);

        return uid;
    }
};