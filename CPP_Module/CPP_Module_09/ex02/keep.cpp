
std::vector<int> ft_PmergeMe_(std::vector<int> vec)
{
    this->sorted_inpput = vec;
    std::sort(sorted_inpput.begin(), sorted_inpput.end());
    if (vec.size() % 2 != 0){
        std::vector<std::pair<int, int> > return_pair_lv1 = ft_PmergeMe_Recursion_lv1(vec, (vec.size() - 1));
        std::cout << "odd : " << std::ends;
        for (size_t i = 0; i < return_pair_lv1.size(); i++)
            std::cout << "[" << return_pair_lv1[i].first << "," << return_pair_lv1[i].second << "]" << " | " << std::ends;
        std::cout << "" << std::endl;
        std::cout << "----------------------------" << std::endl;
        vec = insertVector_lv1(return_pair_lv1, vec.front(), 0);
        displayNumber(vec);
        return vec;
        std::cout << "----------------------------" << std::endl;
        std::vector<std::pair<std::pair<int, int>, std::pair<int, int> > > return_pair_lv2
            = ft_PmergeMe_recussion_lv2(return_pair_lv1, return_pair_lv1.size() - 2);
        for (size_t i = 0; i < return_pair_lv2.size(); i++){
            std::pair<int, int> ai = return_pair_lv2[i].first;
            std::pair<int, int> bi = return_pair_lv2[i].second;
            std::cout << "[" << ai.first << "," << ai.second << "]" << ", " << "[" << bi.first << "," << bi.second << "]" << " | " << std::ends;
        }
        for (size_t i = return_pair_lv1.size() - 1; i <= return_pair_lv1.size() - 1; i++){
            std::cout << "[" << return_pair_lv1[i].first << ", " << return_pair_lv1[i].second << "]" << std::ends; 
        }
        std::cout << "" << std::endl;
    }
    else{
        std::vector<std::pair<int, int> > return_pair_lv1 = ft_PmergeMe_Recursion_lv1(vec, vec.size() - 1);
        for (size_t i = 0; i < return_pair_lv1.size(); i++)
            std::cout << "[" << return_pair_lv1[i].first << "," << return_pair_lv1[i].second << "]" << " | " << std::ends;
        std::cout << "" << std::endl;
        std::cout << "----------------------------" << std::endl;
        vec = insertVector_lv1(return_pair_lv1, vec.front(), 1);
        displayNumber(vec);
        std::cout << "----------------------------" << std::endl;

        std::reverse(return_pair_lv1.begin(), return_pair_lv1.end());
        std::vector<std::pair<std::pair<int, int>, std::pair<int, int> > > return_pair_lv2
            = ft_PmergeMe_recursion_lv2(return_pair_lv1, return_pair_lv1.size() - 1);
        vec = insertVector_lv2(return_pair_lv2, return_pair_lv1.front(), 0);

        for (size_t i = 0; i < return_pair_lv2.size(); i++){
            std::pair<int, int> ai = return_pair_lv2[i].first;
            std::pair<int, int> bi = return_pair_lv2[i].second;
            std::cout << "[" << ai.first << "," << ai.second << "]" << ", " << "[" << bi.first << "," << bi.second << "]" << " | " << std::ends;
        }
        std::cout << "" << std::endl;
        std::cout << "----------------------------" << std::endl;
        displayNumber(vec);
        std::cout << "----------------------------" << std::endl;
        std::reverse(return_pair_lv2.begin(), return_pair_lv2.end());
        std::vector<std::pair<
                std::pair<
                    std::pair<int, int>, 
                    std::pair<int, int>
                >, 
                std::pair<
                    std::pair<int, int>, 
                    std::pair<int, int>
                >
            > > return_pair_lv3 = ft_PmergeMe_recursion_lv3(return_pair_lv2, return_pair_lv2.size() - 1);
        for (size_t i = 0; i < return_pair_lv3.size(); i++){
            std::pair<std::pair<int, int>, std::pair<int, int> > sub1_ai_bi = return_pair_lv3[i].first;
            std::pair<std::pair<int, int>, std::pair<int, int> > sub2_ai_bi = return_pair_lv3[i].second;
            std::pair<int, int> ai = sub1_ai_bi.first;
            std::pair<int, int> bi = sub1_ai_bi.second;
            std::pair<int, int> ai_2 = sub2_ai_bi.first;
            std::pair<int, int> bi_2 = sub2_ai_bi.second;


            std::cout << "[" << ai.first << " " << ai.second << " " << bi.first << " " << bi.second << "]" << ", "
                << "[" << ai_2.first << " " << ai_2.second << " " << bi_2.first << " " << bi_2.second << "]" << " | " << std::ends;
        }
        std::cout << "" << std::endl;
        std::cout << "----------------------------" << std::endl;
        vec = insertVector_lv3(return_pair_lv3, return_pair_lv2.front(),return_pair_lv1.front(), 0);
        displayNumber(vec);
        std::cout << "----------------------------" << std::endl;
        std::reverse(return_pair_lv3.begin(), return_pair_lv3.end());
        std::vector<std::pair<std::pair<
                        std::pair<
                                std::pair<int, int>, 
                                std::pair<int, int>
                            >, 
                            std::pair<
                                std::pair<int, int>, 
                                std::pair<int, int>
                            >
                    >, std::pair<
                            std::pair<
                                std::pair<int, int>, 
                                std::pair<int, int>
                            >, 
                            std::pair<
                                std::pair<int, int>, 
                                std::pair<int, int>
                            >
                    >   
                >    
        >return_pair_lv4 = ft_PmergeMe_recursion_lv4(return_pair_lv3, return_pair_lv3.size() - 1);
        std::reverse(return_pair_lv4.begin(), return_pair_lv4.end());
        for (size_t i = 0; i < return_pair_lv4.size() ; i++)
        {
            std::pair<
                    std::pair<
                                std::pair<int, int>, 
                                std::pair<int, int>
                            >, 
                    std::pair<
                                std::pair<int, int>, 
                                std::pair<int, int>
                    >
            > sub1_ai_bi = return_pair_lv4[i].first;

            std::pair<
                    std::pair<
                                std::pair<int, int>, 
                                std::pair<int, int>
                            >, 
                    std::pair<
                                std::pair<int, int>, 
                                std::pair<int, int>
                    >
            > sub2_ai_bi = return_pair_lv4[i].second;
            std::pair<std::pair<int, int>, std::pair<int, int> > sub1_ai_bi_v1 = sub1_ai_bi.first;
            std::pair<int, int> v1 = sub1_ai_bi_v1.first;
            std::pair<int, int> v2 = sub1_ai_bi_v1.second;
            std::pair<std::pair<int, int>, std::pair<int, int> > sub2_ai_bi_v1 = sub1_ai_bi.second;
            std::pair<int, int> V1 = sub2_ai_bi_v1.first;
            std::pair<int, int> V2 = sub2_ai_bi_v1.second; 
            std::pair<std::pair<int, int>, std::pair<int, int> > sub1_ai_bi_v2 = sub2_ai_bi.first;
            std::pair<int, int> l1 = sub1_ai_bi_v2.first;
            std::pair<int, int> l2 = sub1_ai_bi_v2.second; 
            std::pair<std::pair<int, int>, std::pair<int, int> > sub2_ai_bi_v2 = sub2_ai_bi.second;
            std::pair<int, int> L1 = sub2_ai_bi_v2.first;
            std::pair<int, int> L2 = sub2_ai_bi_v2.second;
            std::cout << "[" << " [" << "[" << v1.first << " " << v1.second << " " << v2.first << " " << v2.second << "] " <<
                        "[" << V1.first << " " << V1.second  << " " << V2.first << " " << V2.second << "]" << "]" << " , " 
                    << "[" << "[" << l1.first << " " << l1.second << " " << l2.first << " " << l2.second << "], " << 
                    "[" << L1.first << " " << L1.second << " " << L2.first << " " <<  L2.second << "]" << "]" << " ] | " << std::ends;
        }
        
        std::cout << "" << std::endl;
        std::cout << "----------------------------" << std::endl;
        vec = insertVector_lv4(return_pair_lv4, return_pair_lv3.front(),return_pair_lv2.front(), return_pair_lv1.front(), 1);
        displayNumber(vec);
    }
    return vec;
}
        // std::cout << "----------------------------" << std::endl;
        // std::cout << "sorted reference : " << std::ends;
        // displayNumber(sorted_inpput);   

//---------------------


void PmergeMe::swapPairs_lv2(std::pair<std::pair<int, int>, std::pair<int, int> > &ai_bi)
{
    std::pair<int, int> sub1_ai_bi = ai_bi.first;
    std::pair<int, int> sub2_ai_bi = ai_bi.second;
    if (sub1_ai_bi.second > sub2_ai_bi.second){
        ai_bi.first = sub2_ai_bi;
        ai_bi.second = sub1_ai_bi; 
    }
}

void swapPairs_lv3(std::pair<
                            std::pair<
                                std::pair<int, int>, 
                                std::pair<int, int>
                            >, 
                            std::pair<
                                std::pair<int, int>, 
                                std::pair<int, int>
                            >
                    > &ai_bi)
{
    std::pair<std::pair<int, int>, std::pair<int, int> > sub1_ai_bi = ai_bi.first;
    std::pair<std::pair<int, int>, std::pair<int, int> > sub2_ai_bi = ai_bi.second;
    std::pair<int, int> sub1_ai_bi_v1 = sub1_ai_bi.second;
    std::pair<int, int> sub2_ai_bi_v1 = sub2_ai_bi.second;
    if (sub1_ai_bi_v1.second > sub2_ai_bi_v1.second){
        std::pair<std::pair<int, int>, std::pair<int, int> > temp = ai_bi.first;
        ai_bi.first = ai_bi.second;
        ai_bi.second = temp; 
    }
}

void swapPairs_lv4(
                    std::pair<std::pair<
                            std::pair<
                                    std::pair<int, int>, 
                                    std::pair<int, int>
                                >, 
                                std::pair<
                                    std::pair<int, int>, 
                                    std::pair<int, int>
                                >
                        >, std::pair<
                                std::pair<
                                    std::pair<int, int>, 
                                    std::pair<int, int>
                                >, 
                                std::pair<
                                    std::pair<int, int>, 
                                    std::pair<int, int>
                                >
                        >
                    >ai_bi)
{
    std::pair<
                std::pair<
                            std::pair<int, int>, 
                            std::pair<int, int>
                        >, 
                std::pair<
                            std::pair<int, int>, 
                            std::pair<int, int>
                >
            > sub1_ai_bi = ai_bi.first;
    
    std::pair<std::pair<int, int>, std::pair<int, int> > sub1_ai_bi_v1 = sub1_ai_bi.second;
    std::pair<int, int> sub1_ai_bi_v2 = sub1_ai_bi_v1.second;
    // sub1_ai_bi_v2.second // 17
    // std::cout << "--> " << sub1_ai_bi_v2.second << " <----" << std::endl;
    std::pair<
                std::pair<
                            std::pair<int, int>, 
                            std::pair<int, int>
                        >, 
                std::pair<
                            std::pair<int, int>, 
                            std::pair<int, int>
                >
            > sub2_ai_bi = ai_bi.second;
    std::pair<std::pair<int, int>, std::pair<int, int> > sub2_ai_bi_v1 = sub2_ai_bi.second;
    std::pair<int, int> sub2_ai_bi_v2 = sub2_ai_bi_v1.second;
    // sub2_ai_bi_v2.second // 21;
    // std::cout << "--> " << sub2_ai_bi_v2.second << " <----" << std::endl;

    if (sub1_ai_bi_v2.second > sub2_ai_bi_v2.second){
        // std::cout << "I was here " << std::endl;
            std::pair<
                std::pair<
                            std::pair<int, int>, 
                            std::pair<int, int>
                        >, 
                std::pair<
                            std::pair<int, int>, 
                            std::pair<int, int>
                >
            > temp = ai_bi.first;
        ai_bi.first = ai_bi.second;
        ai_bi.second = temp;
    }
}
//---------------

std::vector<std::pair<std::pair<int, int>, std::pair<int, int> > > 
PmergeMe::ft_PmergeMe_recursion_lv2(std::vector<std::pair<int, int> > sub_comparisons, int n){
    
    std::vector<std::pair<std::pair<int, int>, std::pair<int, int> > > pair_of_pairs;
    if (n <= 0)
        return pair_of_pairs;
    std::pair<std::pair<int, int>, std::pair<int, int> > ai_bi(sub_comparisons[n], sub_comparisons[n - 1]);
    swapPairs_lv2(ai_bi);
    pair_of_pairs.push_back(ai_bi);
    std::vector<std::pair<std::pair<int, int>, std::pair<int, int> > > lv2_pair_of_pairs = ft_PmergeMe_recursion_lv2(sub_comparisons, n - 2);
    pair_of_pairs.insert(pair_of_pairs.end(), lv2_pair_of_pairs.begin(), lv2_pair_of_pairs.end());
    return pair_of_pairs;
}

std::vector<std::pair<
                        std::pair<
                            std::pair<int, int>, 
                            std::pair<int, int>
                        >, 
                        std::pair<
                            std::pair<int, int>, 
                            std::pair<int, int>
                        >
        > > ft_PmergeMe_recursion_lv3(std::vector<std::pair<std::pair<int, int>, std::pair<int, int> > >  sub_comparisons, int n)
{

    std::vector<std::pair<
                            std::pair<
                                std::pair<int, int>,
                                std::pair<int, int>
                            >, 
                            std::pair<
                                std::pair<int, int>, 
                                std::pair<int, int>
                            >
            > >pair_of_pair_of_pairs;

    if (n <= 0){
        return pair_of_pair_of_pairs;
    }
    
    std::pair<
                std::pair<
                    std::pair<int, int>, 
                    std::pair<int, int>
                >, 
                std::pair<
                    std::pair<int, int>, 
                    std::pair<int, int>
                >
            > ai_bi(sub_comparisons[n], sub_comparisons[n - 1]);
    
    swapPairs_lv3(ai_bi);
    pair_of_pair_of_pairs.push_back(ai_bi);
    std::vector<std::pair<
                            std::pair<
                                std::pair<int, int>, 
                                std::pair<int, int>
                            >, 
                            std::pair<
                                std::pair<int, int>, 
                                std::pair<int, int>
                            >
            > >lv3_pair_of_pairs_of_pairs = ft_PmergeMe_recursion_lv3(sub_comparisons, n - 2);
    pair_of_pair_of_pairs.insert(pair_of_pair_of_pairs.end(), lv3_pair_of_pairs_of_pairs.begin(),lv3_pair_of_pairs_of_pairs.end());
    return pair_of_pair_of_pairs;    
}
//---------

std::vector<int> insertVector_lv2(std::vector<std::pair<std::pair<int, int>, std::pair<int, int> > > return_pair_lv2, std::pair<int, int> last_element, int flag){

    std::vector<int> buffer;
    for (size_t i = 0; i < return_pair_lv2.size(); i++){
        std::pair<int, int> ai = return_pair_lv2[i].first;
        std::pair<int, int> bi = return_pair_lv2[i].second;
        buffer.push_back(ai.first);
        buffer.push_back(ai.second);
        buffer.push_back(bi.first);
        buffer.push_back(bi.second);
    }

    if (flag == 0){

        buffer.push_back(last_element.first);
        buffer.push_back(last_element.second);
    }
    return buffer;
}

std::vector<std::pair<std::pair<
                                    std::pair<
                                        std::pair<int, int>, 
                                        std::pair<int, int>
                                    >, 
                                    std::pair<
                                        std::pair<int, int>, 
                                        std::pair<int, int>
                                    >
                            >, std::pair<
                                    std::pair<
                                        std::pair<int, int>, 
                                        std::pair<int, int>
                                    >, 
                                    std::pair<
                                        std::pair<int, int>, 
                                        std::pair<int, int>
                                    >
                            >
                        >
>ft_PmergeMe_recursion_lv4(
            std::vector<std::pair<
                            std::pair<
                                std::pair<int, int>, 
                                std::pair<int, int>
                            >, 
                            std::pair<
                                std::pair<int, int>, 
                                std::pair<int, int>
                            >
                        >
        >sub_comparisons, int n)
{
    std::vector<std::pair<std::pair<
                            std::pair<
                                    std::pair<int, int>, 
                                    std::pair<int, int>
                                >, 
                                std::pair<
                                    std::pair<int, int>, 
                                    std::pair<int, int>
                                >
                        >, std::pair<
                                std::pair<
                                    std::pair<int, int>, 
                                    std::pair<int, int>
                                >, 
                                std::pair<
                                    std::pair<int, int>, 
                                    std::pair<int, int>
                                >
                        >
                    >    
            >pair_of_pair_of_pairs;
    if (n <= 0){
        return pair_of_pair_of_pairs;
    }

    std::pair<std::pair<
                            std::pair<
                                    std::pair<int, int>, 
                                    std::pair<int, int>
                                >, 
                                std::pair<
                                    std::pair<int, int>, 
                                    std::pair<int, int>
                                >
                        >, std::pair<
                                std::pair<
                                    std::pair<int, int>, 
                                    std::pair<int, int>
                                >, 
                                std::pair<
                                    std::pair<int, int>, 
                                    std::pair<int, int>
                                >
                        >
                    >ai_bi(sub_comparisons[n], sub_comparisons[n - 1]);
    
    swapPairs_lv4(ai_bi);
    pair_of_pair_of_pairs.push_back(ai_bi);
    std::vector<std::pair<std::pair<
                        std::pair<
                                std::pair<int, int>, 
                                std::pair<int, int>
                            >, 
                            std::pair<
                                std::pair<int, int>, 
                                std::pair<int, int>
                            >
                    >, std::pair<
                            std::pair<
                                std::pair<int, int>, 
                                std::pair<int, int>
                            >, 
                            std::pair<
                                std::pair<int, int>, 
                                std::pair<int, int>
                            >
                    >
                >    
        >lv4_pair_of_pair_of_pairs = ft_PmergeMe_recursion_lv4(sub_comparisons, n - 2);
    pair_of_pair_of_pairs.insert(pair_of_pair_of_pairs.end(), lv4_pair_of_pair_of_pairs.begin(), lv4_pair_of_pair_of_pairs.end());
    return pair_of_pair_of_pairs;
}

std::vector<int> insertVector_lv3(
    std::vector<std::pair<
                            std::pair<
                                std::pair<int, int>, 
                                std::pair<int, int>
                            >, 
                            std::pair<
                                std::pair<int, int>, 
                                std::pair<int, int>
                            >
                        > 
                > return_pair_lv3, std::pair<std::pair<int, int>, std::pair<int, int> > last_element
                    , std::pair<int, int> last_element_v1,  int flag){

    std::vector<int> buffer;
    for (size_t i = 0; i < return_pair_lv3.size(); i++){
        std::pair<std::pair<int, int>, std::pair<int, int> > ai = return_pair_lv3[i].first;
        std::pair<std::pair<int, int>, std::pair<int, int> > bi = return_pair_lv3[i].second;
        std::pair<int, int> ai_v1 = ai.first;
        std::pair<int, int> bi_v1 = ai.second;
        std::pair<int, int> ai_v2 = bi.first;
        std::pair<int, int> bi_v2 = bi.second;
        buffer.push_back(ai_v1.first);
        buffer.push_back(ai_v1.second);
        buffer.push_back(bi_v1.first);
        buffer.push_back(bi_v1.second);
        buffer.push_back(ai_v2.first);
        buffer.push_back(ai_v2.second);
        buffer.push_back(bi_v2.first);
        buffer.push_back(bi_v2.second);
    }

    if (flag == 0){
        std::pair<int, int> lai = last_element.first;
        std::pair<int, int> lbi = last_element.second;
        buffer.push_back(lai.first);
        buffer.push_back(lai.second);
        buffer.push_back(lbi.first);
        buffer.push_back(lbi.second);
        buffer.push_back(last_element_v1.first);
        buffer.push_back(last_element_v1.second);
    }
    return buffer;
}

std::vector<int> insertVector_lv4(
        std::vector<std::pair<std::pair<
                        std::pair<
                                std::pair<int, int>, 
                                std::pair<int, int>
                            >, 
                            std::pair<
                                std::pair<int, int>, 
                                std::pair<int, int>
                            >
                    >, std::pair<
                            std::pair<
                                std::pair<int, int>, 
                                std::pair<int, int>
                            >, 
                            std::pair<
                                std::pair<int, int>, 
                                std::pair<int, int>
                            >
                    >
                >    
        > return_pair_lv4, std::pair<
                std::pair<
                    std::pair<int, int>, 
                    std::pair<int, int>
                >, 
                std::pair<
                    std::pair<int, int>, 
                    std::pair<int, int>
                >
            > last_element_lv3,
            std::pair<std::pair<int, int>, std::pair<int, int> > last_element_lv2,
            std::pair<int, int> last_element_lv1,  int flag){

            

    std::vector<int> buffer;
    std::vector<int> buffe2;
    std::vector<int> buffe3;
    std::vector<std::pair<
                            std::pair<
                                std::pair<int, int>, 
                                std::pair<int, int>
                            >, 
                            std::pair<
                                std::pair<int, int>, 
                                std::pair<int, int>
                            >
                        > 
                > test;
    for (size_t i = 0; i < return_pair_lv4.size(); i++){
        test.push_back(return_pair_lv4[i].first);
        
        buffer = insertVector_lv3(test,last_element_lv3.first, last_element_lv2.first, flag);
        test.clear();
        test.push_back(return_pair_lv4[i].second);
        buffe2 = insertVector_lv3(test,last_element_lv3.second, last_element_lv2.second, flag);
        buffer.insert(buffer.end(), buffe2.begin(), buffe2.end());
        std::vector<std::pair<std::pair<int, int>, std::pair<int, int> > > test2;
        test2.push_back(last_element_lv2);
        buffe3 = insertVector_lv2(test2, last_element_lv1, 0);
        buffer.insert(buffer.end(), buffe3.begin(), buffe3.end());
    }
    return buffer;
}