t << "Priority queue: ";
            priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> temp_pq = pq;
            while (!temp_pq.empty()) {
                cout << "(" << temp_pq.top().first << ", " << temp_pq.top().second << ") ";
                temp_pq.pop();
            }
            cout << endl;