//
// Created by 咸的鱼 on 2023/12/3.
//
#include "TokenizorTest.hpp"
#include "gtest/gtest.h"
#include "tokenizers/Unigram/Unigram.hpp"
TEST_F(TokenizerTest, test) {
    auto tokenizer = std::make_shared<mllm::UnigramTokenizer>("../project/android/vocab_uni.mllm");
    std::vector<mllm::token_id_t> ids;
    tokenizer->setSpecialToken("|ENDOFTEXT|");
    std::string text = "Hello world";
     // normalization text
    // replace all " " to "▁"
    std::string text_ = "";
    for (auto &ch : text) {
        if (ch == ' ') {
            text_ += "▁";
        }else {
            text_ += ch;
        }

    }
    // std::replace(text.begin(), text.end(), ' ', L'▁');
    // prepend "_" to text
    std::string new_text = "▁" + std::string(text_);

    tokenizer->tokenize(new_text, ids, true);
    for (auto id : ids) {
        std::cout << id << " ";
    }
    auto result = tokenizer->detokenize(ids);
    std::cout << result << std::endl;


}