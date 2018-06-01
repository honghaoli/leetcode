class SnakeGame {
public:
    /** Initialize your data structure here.
        @param width - screen width
        @param height - screen height 
        @param food - A list of food positions
        E.g food = [[1,1], [1,0]] means the first food is positioned at [1,1], the second is at [1,0]. */
    SnakeGame(int width, int height, vector<pair<int, int>> food) 
        : food(food), width(width), height(height), score(0) {
        snake.emplace_front(0, 0);
        body.insert(0);
    }
    
    /** Moves the snake.
        @param direction - 'U' = Up, 'L' = Left, 'R' = Right, 'D' = Down 
        @return The game's score after the move. Return -1 if game over. 
        Game over when snake crosses the screen boundary or bites its body. */
    int move(string direction) {
        auto &curr = snake.front();
        auto nex = next(curr, direction);
        // cout << "head: " << snake.front().first << ", " << snake.front().second << endl;
        // cout << "back: " << snake.back().first << ", " << snake.back().second << endl;
        body.erase(snake.back().first * width + snake.back().second);   // this line must be before the insert!!!!
        if (collision(nex)) return -1;
        // add head
        snake.push_front(nex);
        body.insert(nex.first * width + nex.second);
        // check next site food
        if (score < food.size() && food[score].first == nex.first && food[score].second == nex.second) {
            score++;
            body.insert(snake.back().first * width + snake.back().second);   // this line must be before the insert!!!!
        } else {
            // no food, the last tail disappear.
            snake.pop_back();
        }
        return score;
    }

private:
    int score;
    int width, height;
    vector<pair<int, int>> food;
    list<pair<int, int>> snake;   // use double linked list to represent the snake, better for search.
    unordered_set<int> body;     // decrease search to O(1)

    pair<int, int> next(pair<int, int> &curr, string &direction) {
        if (direction == "U") 
            return {curr.first - 1, curr.second};
        if (direction == "D") 
            return {curr.first + 1, curr.second};
        if (direction == "L") 
            return {curr.first, curr.second - 1};
        if (direction == "R") 
            return {curr.first, curr.second + 1};
        // should never happen for other values
        throw;
    }

    bool collision(pair<int, int> &pos) {
        int i = pos.first;
        int j = pos.second;
        if (i < 0 || i >= height || j < 0 || j >= width) return true;
        // for (auto it = snake.begin(); it != --snake.end(); it++) {  // do not bite the tail, since head/tail move at the same time!
            // if (it->first == i && it->second == j) return true;
        // }
        // do not bite the tail!
        // cout << body.size() << endl;
        if (body.count(i * width + j) != 0) return true;      // O(1) time search
        return false;
    }
};

/**
 * Your SnakeGame object will be instantiated and called as such:
 * SnakeGame obj = new SnakeGame(width, height, food);
 * int param_1 = obj.move(direction);
 */