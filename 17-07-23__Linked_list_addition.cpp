/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:

    string addTwoStrings(string &s1,string &s2){
        int p1 = s1.length() - 1;
        int p2 = s2.length() - 1;
        int carry = 0;
        string ans = "";
        while(p1 >= 0 && p2 >= 0){
            int temp = (s1[p1] - '0') + (s2[p2] - '0') + carry;
            carry = temp /10;
            temp = temp % 10;
            char c1 = '0' + temp;
            ans += c1;
            p1--;
            p2--;
        }
        while(p1 >= 0){
            int temp = (s1[p1] - '0') + carry;
            carry = temp /10;
            temp = temp % 10;
            char c1 = '0' + temp;
            ans += c1;
            p1--;
        }
        while(p2 >= 0){
            int temp = (s2[p2] - '0') + carry;
            carry = temp /10;
            temp = temp % 10;
            char c1 = '0' + temp;
            ans += c1;
            p2--;
        }
        if(carry > 0){
            char c1 = '0' + carry;
            ans += c1;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        string s1 = "";
        while(l1){
            char c1 = l1->val + '0';
            // cout << l1->val << endl;
            s1 += c1;
            l1 = l1->next;
        }
        // cout << s1 << endl;
        string s2 = "";
        while(l2){
            char c1 = l2->val + '0';
            // cout << l1->val << endl;
            s2 += c1;
            l2 = l2->next;
        }
        // cout << s2 << endl;
        string anss = addTwoStrings(s1,s2);
        // cout << anss << endl;
        ListNode* prev;
        ListNode* head;
        for(int i = 0;i < anss.length();i++){
            if(i == 0){
                ListNode* node = new ListNode(anss[i] - '0');
                prev = node;
                head = node;
            }
            else{
                ListNode* node = new ListNode(anss[i] - '0');
                prev->next = node;
                prev = node;
            }
        }

        return head;
    }
};