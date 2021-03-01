void fill(vector<vector<int>> &image, int sr, int sc, int newColor, int oldColor)
{
    if(0 > sc || 0 > sr || image[0].size() == sc || image.size() == sr)
        return;

    if(image[sr][sc] != oldColor || image[sr][sc] == newColor)
        return;

    image[sr][sc] = newColor;

    fill(image, sr - 1, sc, newColor, oldColor);
    fill(image, sr, sc - 1, newColor, oldColor);
    fill(image, sr + 1, sc, newColor, oldColor);
    fill(image, sr, sc + 1, newColor, oldColor);
}

void floodFill(vector<vector<int>> &image, int sr, int sc, int newColor)
{
    int oldColor = image[sr][sc];
    fill(image, sr, sc, newColor, oldColor);
    return image;
}

int main()
{
    vector<vector<int>> mat { {1, 1, 1}, {1, 1, 0}, {1, 0, 1} };
    int sr = 1, sc = 1, newColor = 2;

    floodFill(mat, sr, sc, newColor);
    for(vector<int> v : mat)
    {
      for(int i : v)
        cout << i << " ";
      cout << "\n";
    }
}
