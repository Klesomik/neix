/**
 * Feed parser class.
 *
 * @package     CRSS
 * @author      Thomas Schwarz
 * @copyright   Copyright (c) 2020, Thomas Schwarz
 * @license     -
 * @since       Version 0.1.0
 * @filesource
 */

#ifndef CRSS_PARSER_H
#define CRSS_PARSER_H

#include "rapidxml/rapidxml.hpp"
#include "feed/FeedLoader.h"

using namespace rapidxml;

namespace crss
{
    class Parser
    {
    public:
        explicit Parser(struct rawRss content);
        ~Parser();

        virtual struct rssItem* getFeedItem() = 0;
        char* convertHtmlToPlaintext(char *text);
        char* formatTimeString(const char *timeString);

    protected:
        xml_document<> xmlDocument;
        xml_node<> *rootNode{};
        xml_node<> *entryNode{};
        struct rawRss *rss{};

        virtual char* getFeedDateFormat() = 0;
        char* getNodeContent(xml_node<> *node);
        char* getNodeAttribute(xml_node<> *node, const char *attribute);
        void setRawRss(struct rawRss rawContent);
    };
}

#endif //CRSS_PARSER_H