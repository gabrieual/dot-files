local function longest_commun_subsequence(work_a, work_b, table)
    for i = 1, #work_a do
    print("i:" .. i)
        for j = 1, #work_b do
            
            if work_a[1] == work_b
            print("j:" .. j)
            if work_a[i] == work_b[j] then
                table[i][j] = table[i-1][j-1] + 1
            else
                table[i][j] = math.max(table[i-1][j], table[i][j-1])
            end
        end
    end
    return table
end

local function longest_commun_substring(work_a, work_b, table)
    
end

local word_a = "fish"
local word_b = "fosh"

local matrix = {}
for i = 1, #word_a do
    table.insert(matrix, {})
    for j = 0, #word_b do
        table[i] = 0
    end
end

local response_table = longest_commun_subsequence(word_a, word_b, table)
print(response_table[#word_a][#word_b])