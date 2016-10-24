// Configs
let debug = true
let defaultUserPassword = 'potato123'
let defaultDescription = "There's nothing here"

// Requirements
let mysql = require('mysql')
let fs = require('fs')
let parseXml = require('xml2js').parseString
let xml = fs.readFileSync('BugReports.xml', 'utf8')

var pool = mysql.createPool({
  connectionLimit: 10,
  host: '127.0.0.1',
  user: 'root',
  password: 'byBvGarJNNBp8mdxBtRHQGouWN6kYg',
  database: 'csci222'
})

function parseBug (bug) {
  // Create user if user referenced does not exist.
  bug.reporter.forEach((reporter) => {
    let username = reporter['_']
    var details = ''
    if (reporter.hasOwnProperty('$')) {
      details = reporter['$']['name'] || 'No information.'
    }
    let password = defaultUserPassword
    let reputation = 0
    let active = true
    if (debug) {
      console.log(`username: ${username}`)
      console.log(`info: ${details}`)
      console.log(`password: ${password}`)
      console.log(`reputation: ${reputation}`)
      console.log(`active: ${active}`)
      console.log('#################################################################')
    }
    insertUserToDB(username, details, password, reputation, active)
  })

  bug.assigned_to.forEach((assignedTo) => {
    let username = assignedTo['_']
    var details = ''
    if (assignedTo.hasOwnProperty('$')) {
      details = assignedTo['$']['name'] || 'No information.'
    }
    let password = defaultUserPassword
    let reputation = 0
    let active = true
    if (debug) {
      console.log(`username: ${username}`)
      console.log(`info: ${details}`)
      console.log(`password: ${password}`)
      console.log(`reputation: ${reputation}`)
      console.log(`active: ${active}`)
      console.log('#################################################################')
    }
    insertUserToDB(username, details, password, reputation, active)
  })

  // Create product if product referenced does not exist
  let product = bug['product']
  insertProductToDB(product)

  // Create product version if product version referenced does not exist
  let version = bug['version']
  insertProductVersionToDB(product, version)

  // Create product milestone if product milestone referenced does not exist
  let targetMilestone = bug['target_milestone']
  insertProductMilestoneToDB(product, version, targetMilestone)

  // Create component if component referenced does not exist
  let component = bug['component']
  insertComponent(component, product)

  // Create bug
  let bugId = bug['bug_id']
  let creationTs = bug['creation_ts']
  let shortDesc = bug['short_desc']
  let deltaTs = bug['delta_ts']
  let reporterAccessible = bug['reporter_accessible']
  let cclistAccessible = bug['cclist_accessible']
  let classificationId = bug['classification_id']
  let classification = bug['classification']
  let repPlatform = bug['rep_platform']
  let opSys = bug['op_sys']
  let bugStatus = bug['bug_status']
  let resolution = bug['resolution']
  let keywords = bug['keywords']
  let priority = bug['priority']
  let bugSeverity = bug['bug_severity']
  let votes = bug['votes']

  if (debug) {
    // console.log(bug)

    console.log(`bugId: ${bugId}`)
    console.log(`creationTs: ${creationTs}`)
    console.log(`shortDesc: ${shortDesc}`)
    console.log(`deltaTs: ${deltaTs}`)
    console.log(`reporterAccessible: ${reporterAccessible}`)
    console.log(`cclistAccessible: ${cclistAccessible}`)
    console.log(`classificationId: ${classificationId}`)
    console.log(`classification: ${classification}`)
    console.log(`product: ${product}`)
    console.log(`component: ${component}`)
    console.log(`version: ${version}`)
    console.log(`repPlatform: ${repPlatform}`)
    console.log(`opSys: ${opSys}`)
    console.log(`bugStatus: ${bugStatus}`)
    console.log(`resolution: ${resolution}`)
    console.log(`keywords: ${keywords}`)
    console.log(`priority: ${priority}`)
    console.log(`bugSeverity: ${bugSeverity}`)
    console.log(`targetMilestone: ${targetMilestone}`)
    console.log(`votes: ${votes}`)
    console.log('############################################################################################')
  }

  insertBugToDB(bugId, creationTs, shortDesc, deltaTs, reporterAccessible, cclistAccessible, classificationId, classification, product, component, version, repPlatform, opSys, bugStatus, resolution, keywords, priority, bugSeverity, targetMilestone, votes)

  let reporter = bug['reporter']
  let assignedTo = bug['assigned_to']
  let attachment = bug['attachment']

  // Create attachments

  // Create assigned

  // Create reporters
}

function insertBugToDB (bugId, creationTs, shortDesc, deltaTs, reporterAccessible, cclistAccessible, classificationId, classification, product, component, version, repPlatform, opSys, bugStatus, resolution, keywords, priority, bugSeverity, targetMilestone, votes) {
  let values = {
    bug_id: bugId,
    creation_ts: creationTs,
    short_desc: shortDesc,
    delta_ts: deltaTs,
    reporter_accessible: reporterAccessible,
    cclist_accessible: cclistAccessible,
    classification_id: classificationId,
    classification: classification,
    product: product,
    component: component,
    version: version,
    rep_platform: repPlatform,
    op_sys: opSys,
    bug_status: bugStatus,
    resolution: resolution,
    keywords: keywords,
    priority: priority,
    bug_severity: bugSeverity,
    target_milestone: targetMilestone,
    votes: votes
  }
  pool.query('INSERT IGNORE INTO bug SET ?', values)
}

function insertUserToDB (username, details, password, reputation, active) {
  let values = {
    username: username,
    details: details,
    password: password,
    reputation: reputation,
    active: active
  }
  pool.query('INSERT IGNORE INTO user SET ?', values)
}

function insertProductToDB (product) {
  let values = {
    title: product,
    description: defaultDescription
  }
  pool.query('INSERT IGNORE INTO product SET ?', values)
}

function insertProductVersionToDB (product, version) {
  let values = {
    product_title: product,
    version: version
  }
  pool.query('INSERT IGNORE INTO product_version SET ?', values)
}

function insertProductMilestoneToDB (product, version, milestone) {
  let values = {
    product_title: product,
    product_version: version,
    title: milestone,
    description: defaultDescription
  }
  pool.query('INSERT IGNORE INTO product_milestone SET ?', values)
}

function insertComponent (component, product) {
  let values = {
    product: product,
    title: component,
    description: defaultDescription
  }
  pool.query('INSERT IGNORE INTO component SET ?', values)
}

parseXml(xml, function (err, result) {
  if (err) {
    console.err(`${err}, Invalid XML`)
    return
  }
  result.root.bug.forEach(parseBug)
})

pool.end()
