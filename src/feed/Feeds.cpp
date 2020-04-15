/**
 * Feeds singleton class.
 *
 * @package     CRSS
 * @author      Thomas Schwarz
 * @copyright   Copyright (c) 2020, Thomas Schwarz
 * @license     -
 * @since       Version 0.1.0
 * @filesource
 */

#include <stdio.h>
#include <string.h>
#include <cstdlib>
#include "feed/Feeds.h"

using namespace crss;


/**
 * Instance
 */
Feeds *Feeds::instance = nullptr;


/**
 * Constructor
 */
Feeds::Feeds()
{
    this->count = 0;
}


/**
 * Get instance of feeds
 *
 * @return  {*Feeds}
 */
Feeds *Feeds::getInstance()
{
    if (!instance)
    {
        instance = new Feeds;
    }

    return instance;
}


/**
 * Add given feed
 *
 * @param   {struct rss*}   newFeed     - New feed to add
 * @return  {boolean}                   - true on success, false else
 */
bool Feeds::addFeed(struct rss *newFeed)
{
    this->rssFeeds[this->count] = (struct rss*) malloc(sizeof(struct rss));
    memcpy(&this->rssFeeds[this->count], &newFeed, sizeof(newFeed));
    this->count++;

    return true;
}


/**
 * Add given article to feed
 *
 * @param   {int}               feedIndex       - Index of feed
 * @param   {int}               articleIndex    - Index of new article
 * @param   {struct rssItem *}  newArticle      - The new article to add
 * @return  {boolean}                           - true on success, false else
 */
bool Feeds::addArticleToFeed(int feedIndex, int articleIndex, struct rssItem *newArticle)
{
    // TODO: check if index exists!
    this->rssFeeds[feedIndex]->items[articleIndex] = (struct rssItem*) malloc(FEEDS_MAX * sizeof(struct rssItem));
    this->rssFeeds[feedIndex]->items[articleIndex] = newArticle;

    return true;
}


/**
 * Get feed of given index
 *
 * @param   {int}           index   - Index of feed which should be returned
 * @return  {struct rss*}           - RSS feed
 */
struct rss *Feeds::getFeed(int index)
{
    // TODO: check if index exists!
    return this->rssFeeds[index];
}


/**
 * Get specific article of feed
 *
 * @param   {int}               feedIndex       - Index of feed
 * @param   {int}               articleIndex    - Index of article
 * @return  {struct rssItem*}                   - RSS article of feed
 */
struct rssItem * Feeds::getArticleOfFeed(int feedIndex, int articleIndex)
{
    // TODO: check if index exists!
    return this->rssFeeds[feedIndex]->items[articleIndex];
}


/**
 * Get count of all feeds
 *
 * @return  {int}   - Count of feeds
 */
int Feeds::getFeedCount()
{
    return this->count;
}