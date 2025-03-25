local function longest_commun_subsequence(word_a, word_b, table)

    for i = 1, #word_a do
        for j = 1, #word_b do
            if word_a[i] == word_b[j] then
                if (i > 1 and j > 1) then
                     table[i][j] = table[i-1][j-1] + 1
                else
                    table[i][j] = 1
                end
            else
                if (i > 1 and i > 1) then 
                    table[i][j] = math.max(table[i-1][j], table[i][j-1])
                elseif (i>1) then
                    table[i][j] = table[i - 1][j]
                elseif (j>1) then
                    table[i][j] = table[i][j -1]
                end
            end
        end
    end
    return table
end

local function longest_commun_substring(word_a, word_b, table)
    
end

local word_a = "fosh"
local word_b = "fish"

local matrix = {}
for i = 1, #word_a do
    table.insert(matrix, {})
    for j = 0, #word_b do
        table.insert(matrix[i], 0)
    end
end

local response_table = longest_commun_subsequence(word_a, word_b, matrix)
for i=1, #word_a do
    for j=1, #word_b do
        io.write(response_table[i][j])
    end
    print("")
end
print(response_table[#word_a][#word_b])